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

bool File::containsWord(std::string word) {
    for(auto &i: lines) {
        if(i.find(word) != std::string::npos)
            return true;
    }
    
    return false;
}