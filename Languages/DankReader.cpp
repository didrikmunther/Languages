//
//  DankReader.cpp
//  Languages
//
//  Created by Didrik Munther on 02/12/15.
//  Copyright © 2015 Didrik Munther. All rights reserved.
//

#include <sstream>
#include <stdlib.h>

#include "DankReader.hpp"

using namespace std::chrono;


DankReader::DankReader()
    : delay(10)
{
}

void DankReader::execute(std::string initFile) {
    File init(initFile);
    auto elements = parseInitFile(&init);
    
    for(auto& i: elements) {    // Load files and put them in a map
        File* file = new File(i.second);
        fileMap[i.first] = file;
    }
    
    parseCommand({"help"});
    
    while(true) {               // Check for input
        printString("_________________________\n> ");
        std::string input = "";
        std::getline(std::cin, input);
        std::vector<std::string> commands = splitString(input, " ");
        
        if(parseCommand(commands) == QUIT)
            break;
    }
    
    for(auto& i: fileMap) {     // Cleanup files
        delete i.second;
    }
    fileMap.clear();
}

Status DankReader::parseCommand(std::vector<std::string> commands) {
    if(commands.empty())
        return NORMAL;
    
    if(commands[0] == "exit" || commands[0] == "quit")
        return QUIT;
    
    if(commands[0] == "help" || commands[0] == "?") {
        printHelp();
        return NORMAL;
    }
    
    if(commands[0] == "list") {
        printIntro(&fileMap);
        return NORMAL;
    }
    
    if(commands[0] == "open") {
        if(commands.size() <= 1) {
            printString("Invalid parameters for \"open\".\n");
            return NORMAL;
        }
        
        if(fileMap.find(commands[1]) == fileMap.end()) {
            printString("No such file with name \"" + commands[1] + "\"\n");
            return NORMAL;
        }
        
        commands.erase(commands.begin());
        for(auto& i: commands) {
            printString("\n------------------\n\n");
            File* fileToPrint = fileMap[i];
            printString(fileToPrint->lines);
//            fileToPrint->printFile(delay);
        }
        
        return NORMAL;
    }
    
    if(commands[0] == "clear") {
#ifdef _WIN32
        system("cls");
#elif __APPLE__
        system("clear");
#elif __linux__
        system("clear");
#else
        std::cout << "Unknown enviroment.\n";
#endif
        return NORMAL;
    }
    
    if(commands[0] == "delay") {
        if(commands.size() <= 1) {
            printString("Delay is " + std::to_string(delay) + "\n");
            return NORMAL;
        }
        if(!isNumber(commands[1])) {
            printString("Invalid parameter to command \"delay\"\n");
            return NORMAL;
        }
        
        delay = std::stoi(commands[1]);
        printString({"Set delay to ", std::to_string(delay), "\n"});
        return NORMAL;
    }
    
    printString("No such command \"" + commands[0] + "\"\nType \"?\" or \"help\" for help.\n");
    return NORMAL;
}

std::vector<std::string> DankReader::splitString(std::string val, const char* delim) {
    std::vector<std::string> toReturn;
    
    std::stringstream ss(val);
    std::string item;
    
    while(std::getline(ss, item, *delim))
        toReturn.push_back(item);
    
    return toReturn;
}

std::vector<std::pair<std::string, std::string>> DankReader::parseInitFile(File* file) {
    std::vector<std::pair<std::string, std::string>> elements;
    
    for(auto& i: file->lines) {
        std::stringstream ss(i);
        std::string item;
        std::string item2;
        const char* delim = " | ";
        
        std::getline(ss, item, *delim);
        std::getline(ss, item2, *delim); // Split twice because wierd behaviour
        std::getline(ss, item2, *delim);
        
        if(item != "" && item2 != "")
            elements.push_back(std::make_pair(item, item2));
    }
    
    return elements;
}

void DankReader::printString(std::string toPrint) {
    milliseconds del(delay);
    
    steady_clock::time_point now = steady_clock::now();
    steady_clock::time_point last = steady_clock::now();
    
    for(auto &letter: toPrint) {
        last = now;
        std::cout << letter;
        std::cout.flush();
        while(true) {
            now = steady_clock::now();
            if(duration_cast<milliseconds>(now - last) >= del)
                break;
        }
    }
}

void DankReader::printString(std::vector<std::string> toPrint) {
    std::string toPrintString = "";
    for(auto& line: toPrint) {
        toPrintString += line + '\n';
    }
    
    printString(toPrintString);
}

void DankReader::printIntro(std::map<std::string, File*>* fileMap) {
    printString("[ ========= ]\n");
    
    for(auto& i: *fileMap) {
        printString(i.first + "\n");
    }
    
    printString("[ ========= ]\n");
}

void DankReader::printHelp() {
    std::vector<std::string> toPrint = {
    "[SFRS] Simple File Reading System.",
    "==================================",
    "Commands: ",
    "\"help\"     : Prints the different commands and their use.",
    "\"exit\"     : Exits the program",
    "\"list\"     : Lists all the different programming languages available to read about.",
    "\"open\"     : Open a document about a programming language, second argument is the name of the language.",
    "\"delay\"    : Set the delay at which the file is printed.",
    "\"clear\"    : Clear the screen if possible."};
    
    printString(toPrint);
}

bool DankReader::isNumber(std::string val) {
    std::string::const_iterator it = val.begin();
    while (it != val.end() && std::isdigit(*it)) ++it;
    return !val.empty() && it == val.end();
}