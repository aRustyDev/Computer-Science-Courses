/*      Title: CylinderType.h | Problem 11.04
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
 *      Purpose: Define the Class for a CylinderType, Inheriting from CircleType
 *
 */


#ifndef PROB11_04_CYLINDERTYPE_FR_CIRCLETYPE_CYLINDERTYPE_H
#define PROB11_04_CYLINDERTYPE_FR_CIRCLETYPE_CYLINDERTYPE_H

#include <iostream>
#include <math.h>
#include "circleType.h"

class cylinderType : public circleType
{
public:

    void setHeight(double r);
    //Function to set the radius.
    //Postcondition: if (r >= 0) radius = r;
    //               otherwise radius = 0;

    double volume();
    //Function to return the Volume of a cylinder.
    //Postcondition: Volume is calculated and returned.

    double surfaceArea();
    //Function to return the Surface Area of a cylinder.
    //Postcondition: Surface Area is calculated and returned.

    void printVolume();
    //Function to print the Volume of a cylinder.
    //Postcondition: Volume is calculated and returned.

    void printSurfaceArea();
    //Function to print the Surface Area of a cylinder.
    //Postcondition: Surface Area is calculated and returned.

    void printCylinder();
    //Function to print the Values of the Cylinder.
    //Postcondition: Outputs Radius, Area, & Circumference of this->cylinderType.

    cylinderType(double r = 0, double h = 0);
    //Constructor with a default parameter.
    //Radius is set according to the parameter.
    //The default value of the radius is 0.0;
    //Postcondition: radius = r;

private:
    double height;

};


//Implementation File for the class circleType

void cylinderType::setHeight(double r){
    if (r >= 0)
        height = r;
    else
        height = 0;
}
double cylinderType::volume(){
    return 3.1416 * pow(getRadius(), 2) * height;
}
double cylinderType::surfaceArea(){
    // Surface Area = 2π*R*H + 2πR^2
    return (2 * 3.1416 * getRadius() * height) + (2 * 3.1416 * pow(getRadius(), 2) );
}
void cylinderType::printVolume(){
    std::cout <<"\n\tVolume: \t\t"<< volume();
}
void cylinderType::printSurfaceArea(){
    std::cout <<"\n\tSurface Area: \t"<< surfaceArea();

}
void cylinderType::printCylinder(){

    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout <<"\n::Cylinder: "<<std::endl;
    std::cout<<"\tRadius:\t\t\t"<<getRadius();
    printVolume();
    printSurfaceArea();
}
cylinderType::cylinderType(double r, double h){
    setRadius(r);
    setHeight(h);
}

#endif //PROB11_04_CYLINDERTYPE_FR_CIRCLETYPE_CYLINDERTYPE_H
