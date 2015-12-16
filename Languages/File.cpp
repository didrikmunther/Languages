//
//  File.cpp
//  Languages
//
//  Created by Didrik Munther on 18/11/15.
//  Copyright © 2015 Didrik Munther. All rights reserved.
//

#include <chrono>
#include <ctime>

#include "File.h"

using namespace std::chrono;


File::File(std::string path) {
    file.open(path.c_str());
    
    if (!file) {
        std::cout << "Could not open file...\n";
        return;
    }
    
    std::string line;
    if (file.is_open())
        while (std::getline(file, line))
            lines.push_back(line);
}

File::~File() {
    file.close();
}

void File::printFile(int delay) {
<<<<<<< HEAD
    std::chrono::milliseconds del(delay);
    
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point last = std::chrono::steady_clock::now();
=======
    milliseconds del(delay);
    
    steady_clock::time_point now = steady_clock::now();
    steady_clock::time_point last = steady_clock::now();
>>>>>>> Malaxiz/master
    
    for(auto &line: lines) {
        for(auto& letter: line) {
            last = now;
            std::cout << letter;
            std::cout.flush();
            while(true) {
<<<<<<< HEAD
                now = std::chrono::steady_clock::now();
                if(duration_cast<milliseconds>(now - last) > del) {
                    break;
                }
=======
                now = steady_clock::now();
                if(duration_cast<milliseconds>(now - last) >= del)
                    break;
>>>>>>> Malaxiz/master
            }
        }
        std::cout << "\n";
    }
}

bool File::containsWord(std::string word) {
    for(auto &i: lines) {
        if(i.find(word) != std::string::npos)
            return true;
    }
    
    return false;
}