/*      Title: Cylinder Business | Problem 11.04
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
    double radius;
    double height;
    double shipCost;
    double paintCost;

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "\n:: Container Dimensions ::";
        std::cout << "\n\tRadius (ft):";
        std::cin >> radius;
            cylinder.setRadius(radius);
        std::cout << "\n\tHeight (ft):";
        std::cin >> height;
            cylinder.setHeight(height);
    std::cout << "\n\n:: Unit Costs ::";
        std::cout << "\n::Shipping Cost::";
        std::cout << "\n\t $ per Liter: $";
        std::cin >> shipCost;
        std::cout << "\n::Paint Cost::";
        std::cout << "\n\t $ per Sq Ft: $";
        std::cin >> paintCost;


    std::cout << "\n\n:: :: :: :: :: :: :: :: ::";
    std::cout << "\n\n:: :: :: :: :: :: :: :: ::";

    std::cout << "\n\n:: Receipt ::";
    std::cout << "\n\tShipping Cost: $" << shipCost * cylinder.volume() * 28.32;
    std::cout << "\n\tPaint Cost: $" << paintCost * cylinder.surfaceArea();



    return 0;
}//end main
