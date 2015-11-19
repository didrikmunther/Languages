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
        
        elements.push_back(std::make_pair(item, item2));
    }
    
    return elements;
}

int main(int argc, const char * argv[]) {
    
    File init("Files/intro.dank");
    auto elements = parseInitFile(&init);
    
    for(auto& i: elements) {
        std::cout << "_________________________\n\n";
        std::cout << ">> " << i.first << " <<\n";
        File file(i.second);
        file.printFile();
    }
    
    return 0;
}
