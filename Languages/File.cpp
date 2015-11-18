//
//  File.cpp
//  Languages
//
//  Created by Didrik Munther on 18/11/15.
//  Copyright © 2015 Didrik Munther. All rights reserved.
//

#include "File.h"


File::File(std::string path) {
    std::ifstream file;
    file.open(path.c_str());
    
    if (!file) {
        std::cout << "Could not open file...\n";
        return;
    }
    
    std::string line;
    if (file.is_open())
        while (std::getline(file, line))
            lines.push_back(line);
    
    if(containsWord("Java"))
        std::cout << "Thobias sluta skriva om Java.\n";
    
    file.close();
}

void File::printFile() {
    for(auto &i: lines)
        std::cout << i << "\n";
}

bool File::containsWord(std::string word) {
    
    for(auto &i: lines) {
        if(i.find(word) != std::string::npos)
            return true;
    }
    
    return false;
}