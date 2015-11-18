//
//  File.hpp
//  Languages
//
//  Created by Didrik Munther on 18/11/15.
//  Copyright © 2015 Didrik Munther. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class File {
    
public:
    File(std::string path) {
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
    }
    
    void printFile() {
        for(auto &i: lines) {
            std::cout << i << "\n";
        }
    }
    
    bool containsWord(std::string word) {
        
        for(auto &i: lines) {
            if(i.find(word) != std::string::npos)
                return true;
        }
        
        return false;
    }
    
    std::vector<std::string> lines;
    
};

#endif /* File_hpp */
