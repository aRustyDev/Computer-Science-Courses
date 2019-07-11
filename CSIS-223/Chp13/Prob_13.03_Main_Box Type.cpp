/*      Title: boxType.h | Problem 13.03
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp13
 *
 *      Purpose: Define the Class for boxType, so as to practice with overloading functions.
 *
 */
#include <iostream>
#include "boxType.h"


int main()
{
    boxType box1 = boxType(3,4,5);
    boxType box2 = boxType(4,3,5);

    box1.print();
    cout << box1.volume();
    box2.print();
    cout << box2.volume();

    boxType box3 = box1 + box2;

    box3.print();
    cout << box3.volume();

    cout << (box1 == box2);
    cout << (box1 + box2 == box3);

    box2.doubleDimensions();

    cout << (box2 > box3);
    
    box2.print();
    cout << box2.volume();

    return 0;
}
