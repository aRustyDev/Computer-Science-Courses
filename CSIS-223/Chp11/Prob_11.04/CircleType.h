/*      Title: CircleType.h | Problem 11.04
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
 *      Purpose: Define the Class for a CirlceType
 *
 *      Pulled directly from DS Malik's, C++ Programming from Problem Analysis to Program Design
 */

#ifndef PROB11_04_CYLINDERBUSINESS_CIRCLETYPE_H
#define PROB11_04_CYLINDERBUSINESS_CIRCLETYPE_H

#include <iostream>
#include <iomanip>

class circleType{
public:
    void setRadius(double r);
    //Function to set the radius.
    //Postcondition: if (r >= 0) radius = r;
    //               otherwise radius = 0;

    double getRadius();
    //Function to return the radius.
    //Postcondition: The value of radius is returned.

    double area();
    //Function to return the area of a circle.
    //Postcondition: Area is calculated and returned.

    double circumference();
    //Function to return the circumference of a circle.
    //Postcondition: Circumference is calculated and returned.

    void printArea();
    //Function to print the Area of a circle.
    //Postcondition: Area is calculated and returned.

    void printCircumference();
    //Function to print the Area of a circle.
    //Postcondition: Area is calculated and returned.

    void printCircle();
    //Function to print the Values of the circle.
    //Postcondition: Outputs Radius, Area, & Circumference of this->circleType.

    circleType(double r = 0);
    //Constructor with a default parameter.
    //Radius is set according to the parameter.
    //The default value of the radius is 0.0;
    //Postcondition: radius = r;

private:
    double radius;
};


//Implementation File for the class circleType

void circleType::setRadius(double r){
    if (r >= 0)
        radius = r;
    else
        radius = 0;
}
double circleType::getRadius(){
    return radius;
}
double circleType::area(){
    return 3.1416 * radius * radius;
}
double circleType::circumference(){
    return 2 * 3.1416 * radius;
}
void circleType::printArea() {
    std::cout<<"\n\tArea: \t\t\t"<< area();
}
void circleType::printCircumference(){
    std::cout<<"\n\tCircumference: \t"<<circumference();
}
void circleType::printCircle(){

    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout <<"\n::Cirle:: "<<std::endl;
    std::cout<<"\tRadius:\t\t\t"<<getRadius();
    printArea();
    printCircumference();
}
circleType::circleType(double r){
    setRadius(r);
}

#endif //PROB11_04_CYLINDERBUSINESS_CIRCLETYPE_H
