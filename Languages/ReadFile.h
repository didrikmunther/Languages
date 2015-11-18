//
//  ReadFile.h
//  Languages-lucas
//
//  Created by Lucas Karlsson on 18/11/15.
//  Copyright (c) 2015 Lucas Karlsson. All rights reserved.
//

#ifndef __Languages_lucas__ReadFile__
#define __Languages_lucas__ReadFile__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class ReadFile {
    
public:
    ReadFile();
    void readFile(std::string fileName);
    void initFile(std::string fileName);
    
    std::ifstream file;
    std::string line;
    std::vector<std::string> files;
};

#endif /* defined(__Languages_lucas__ReadFile__) */
