//
//  DankReader.hpp
//  Languages
//
//  Created by Didrik Munther on 02/12/15.
//  Copyright © 2015 Didrik Munther. All rights reserved.
//

#ifndef DankReader_hpp
#define DankReader_hpp

#include <stdio.h>
#include <map>
#include <vector>

#include "File.h"


class DankReader {
    
public:
    DankReader();
    
    void execute(std::string initFile);
    
private:
    bool isNumber(std::string val);
    
    void printHelp();
    void printIntro(std::map<std::string, File*>* fileMap);
    
    std::vector<std::pair<std::string, std::string>> parseInitFile(File* file);
    std::vector<std::string> splitString(std::string val, const char* delim);
    
    int delay;
    
};

#endif /* DankReader_hpp */
