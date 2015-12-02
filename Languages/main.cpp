//
//  main.cpp
//  Languages-lucas
//
//  Created by Lucas Karlsson on 18/11/15.
//  Copyright (c) 2015 Lucas Karlsson. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "File.h"


std::vector<std::string> splitString(std::string val, const char* delim) {
    std::vector<std::string> toReturn;
    
    std::stringstream ss(val);
    std::string item;
    
    while(std::getline(ss, item, *delim))
        toReturn.push_back(item);
    
    return toReturn;
}

std::vector<std::pair<std::string, std::string>> parseInitFile(File* file) {
    std::vector<std::pair<std::string, std::string>> elements;
    
    for(auto& i: file->lines) {
        std::stringstream ss(i);
        std::string item;
        std::string item2;
        const char* delim = " | ";
        
        std::getline(ss, item, *delim);
        std::getline(ss, item2, *delim);
        std::getline(ss, item2, *delim);
        
        if(item != "" && item2 != "")
            elements.push_back(std::make_pair(item, item2));
    }
    
    return elements;
}

void printIntro(std::map<std::string, File*>* fileMap) {
    std::cout << "[ ========= ]\n";
    
    for(auto& i: *fileMap) {
        std::cout << i.first << "\n";
    }
    
    std::cout << "[ ========= ]\n";
}

void printHelp() {
    std::cout << "[SFRS] Simple File Reading System.\n";
    std::cout << "==================================\n";
    std::cout << "Commands: \n";
    std::cout << "\"help\"     : Displays this window.\n";
    std::cout << "\"exit\"     : Exits the program\n";
    std::cout << "\"list\"     : Lists all the different programming languages available to read about.\n";
    std::cout << "\"open\"     : Open a document about a programming language, second argument is the name of the language.\n";
    std::cout << "\"delay\"    : Set the delay at which the file is printed.\n";
}

bool isNumber(std::string val) {
    std::string::const_iterator it = val.begin();
    while (it != val.end() && std::isdigit(*it)) ++it;
    return !val.empty() && it == val.end();
}

int main(int argc, const char * argv[]) {
    
    File init("Files/intro.dank");
    auto elements = parseInitFile(&init);
    int delay = 20;
    std::string prevCommand = "";
    
    std::map<std::string, File*> fileMap;
    
    for(auto& i: elements) {    // Load files and put them in a map
        File* file = new File(i.second);
        fileMap[i.first] = file;
    }
    
    while(true) {               // Check for input
        std::cout << "_________________________\n> ";
        std::string input = "";
        std::getline(std::cin, input);
        std::vector<std::string> commands = splitString(input, " ");
        
        if(commands.empty())
            continue;
        
        if(commands[0] == "exit" || commands[0] == "quit")
            break;
        
        if(commands[0] == "help" || commands[0] == "?") {
            printHelp();
            continue;
        }
        
        if(commands[0] == "list") {
            printIntro(&fileMap);
            continue;
        }
        
        if(commands[0] == "open") {
            if(commands.size() <= 1) {
                std::cout << "Invalid parameters for \"open\".\n";
                continue;
            }
            
            if(fileMap.find(commands[1]) == fileMap.end()) {
                std::cout << "No such file with name \"" << commands[1] << "\"\n";
                continue;
            }
            
            commands.erase(commands.begin());
            for(auto& i: commands) {
                std::cout << "\n------------------\n\n";
                File* fileToPrint = fileMap[i];
                fileToPrint->printFile(delay);
            }
            
            continue;
        }
        
        if(commands[0] == "delay") {
            if(commands.size() <= 1) {
                std::cout << "Delay is " << delay << "\n";
                continue;
            }
            if(!isNumber(commands[1])) {
                std::cout << "Invalid parameter to command \"delay\"\n";
                continue;
            }
            
            delay = std::stoi(commands[1]);
            std::cout << "Set delay to " << delay << "\n";
            continue;
        }
        
        std::cout << "No such command \"" << commands[0] << "\"\nType \"?\" or \"help\" for help.\n";
    }
    
    
    
    for(auto& i: fileMap) {     // Cleanup files
        delete i.second;
    }
    fileMap.clear();
    
    return 0;
}
