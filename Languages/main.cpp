//
//  main.cpp
//  Languages-lucas
//
//  Created by Lucas Karlsson on 18/11/15.
//  Copyright (c) 2015 Lucas Karlsson. All rights reserved.
//

#include <iostream>
#include "File.h"

int main(int argc, const char * argv[]) {
    File file("Files/test.txt");
    file.printFile();

    return 0;
}
