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
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <string>
>>>>>>> Malaxiz/master
=======
#include <string>
>>>>>>> Malaxiz/master

#include "File.h"


<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> Malaxiz/master
enum Status {
    NORMAL  = 0,
    QUIT    = 1
};

<<<<<<< HEAD
>>>>>>> Malaxiz/master
=======
>>>>>>> Malaxiz/master
class DankReader {
    
public:
    DankReader();
    
    void execute(std::string initFile);
    
private:
<<<<<<< HEAD
<<<<<<< HEAD
=======
    Status parseCommand(std::vector<std::string> commands);
    
>>>>>>> Malaxiz/master
=======
    Status parseCommand(std::vector<std::string> commands);
    
>>>>>>> Malaxiz/master
    bool isNumber(std::string val);
    
    void printHelp();
    void printIntro(std::map<std::string, File*>* fileMap);
    
    std::vector<std::pair<std::string, std::string>> parseInitFile(File* file);
    std::vector<std::string> splitString(std::string val, const char* delim);
    
<<<<<<< HEAD
<<<<<<< HEAD
=======
    std::map<std::string, File*> fileMap;
    
>>>>>>> Malaxiz/master
=======
    std::map<std::string, File*> fileMap;
    
>>>>>>> Malaxiz/master
    int delay;
    
};

#endif /* DankReader_hpp */
