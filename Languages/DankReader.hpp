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
#include <string>

#include "File.h"


enum Status {
    NORMAL  = 0,
    QUIT    = 1
};

class DankReader {
    
public:
    DankReader();
    
    void execute(std::string initFile);
    
private:
    Status parseCommand(std::vector<std::string> commands);
    void printString(std::string toPrint);
    void printString(std::vector<std::string> toPrint);
    
    bool isNumber(std::string val);
    
    void printHelp();
    void printIntro(std::map<std::string, File*>* fileMap);
    
    std::vector<std::pair<std::string, std::string>> parseInitFile(File* file);
    std::vector<std::string> splitString(std::string val, const char* delim);
    
    std::map<std::string, File*> fileMap;
    
//    template<typename Head>
//    void print(Head head) {
//        
//    }
//    
//    template<typename Head, typename ... Tail>
//    void print(Head&& head, Tail&& ... tail) {
//        print(std::forward<Tail>(tail) ...);
//    }
    
    int delay;
    
};

#endif /* DankReader_hpp */
