/*      Title: CylinderType From CircleType | Problem 11.04
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp11/Prob_11.04
 *
 *      Purpose: Inherit the Features and Methods of a Cirlce to a Cylinder
 *
 * */ //Notes / To-Do's Block

#include <iostream>
#include <iomanip>
#include "cylinderType.h"

int main()
{
    //Local Objects
    circleType circle = circleType(1);
    cylinderType cylinder = cylinderType(1,2);

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "\n\n::Before::";
        circle.printCircle();
        circle.setRadius(2);

    std::cout<< "\n\n::After::";
        circle.printCircle();

    // -----
    std::cout<< "\n\n:: :: :: :: :: :: ::";
    // -----

    std::cout << "\n\n::Before::";
        cylinder.printCylinder();
        cylinder.setRadius(2);
        cylinder.setHeight(4);

    std::cout<< "\n\n::After::";
        cylinder.printCylinder();

    return 0;
}//end main
