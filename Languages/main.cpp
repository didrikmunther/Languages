//
//  main.cpp
//  Languages-lucas
//
//  Created by Lucas Karlsson on 18/11/15.
//  Copyright (c) 2015 Lucas Karlsson. All rights reserved.
//

#include <iostream>
#include "ReadFile.h"

int main(int argc, const char * argv[]) {
    ReadFile f;
    f.readFile("Files/test.txt");

    return 0;
}
