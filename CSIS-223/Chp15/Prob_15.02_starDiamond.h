/*      Title: starDiamond.h | Problem 15.02
 *      Author: Adam Smith | RedGrinGrumbler
 *
 *              ::Compiler Info::
 *      CMD: cpp --version
 *          Apple LLVM version 10.0.1 (clang-1001.0.46.4)
 *          Target: x86_64-apple-darwin18.6.0
 *          Thread model: posix
 *      CMD: gcc --version
 *          Apple LLVM version 10.0.1 (clang-1001.0.46.4)
 *          Target: x86_64-apple-darwin18.6.0
 *          Thread model: posix
 *
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp15
 *
 *      Purpose: Build an diamond of asterisks, that is 'n' wide at its middle.
 *
 */

#ifndef PROB15_02_DIAMONDPATTERN_H
#define PROB15_02_DIAMONDPATTERN_H

#include <iostream>

using namespace std;

void printDiamond(int count, int num){
    int i = num;
    while(i > count){
        cout << " ";
        i--;
    }
    for(int j = 0; j < i; j++){
        cout << "x ";
    }
    cout << "\n";
    if (count < num) printDiamond(count + 1, num);
    for(int j = num + 1; j > i; j--){
        cout << " ";
    }
    for(int j = 1; j < i; j++){
        cout << "x ";
    }
    cout << "\n";

}

#endif //PROB15_02_DIAMONDPATTERN_H
