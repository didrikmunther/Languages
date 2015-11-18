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
    File(std::string path);
    
    void printFile();
    bool containsWord(std::string word);
    
    std::vector<std::string> lines;
    
};

#endif /* File_hpp */
