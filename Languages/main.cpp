//
//  main.cpp
//  Languages-lucas
//
//  Created by Lucas Karlsson on 18/11/15.
//  Copyright (c) 2015 Lucas Karlsson. All rights reserved.
//

#include <iostream>
#include <map>

#include "File.h"


int main(int argc, const char * argv[]) {
    std::vector<std::string> files = {
        "files/intro.dank" ,
        "files/brainfuck.dank",
        "files/python.dank"
    };

    for(auto &i: files) {
        File file(i);
        file.printFile();
    }
    
    return 0;
}
