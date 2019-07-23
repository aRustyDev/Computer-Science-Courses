/*      Title: carClass.cpp | Problem 15.02
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/FinalProject
 *
 *      Purpose: Final Project, create a car class that 'simulates a car'.
 *
 */

#include <iostream>
#include "carClass.h"

using namespace std;

int main () {

    string yr, model, make;

    cout << "\nVehicle Year: ";
    cin >> yr;
    cout << "Vehicle Make: ";
    cin >> make;
    cout << "Vehicle Model: ";
    cin >> model;

    carClass myCar = carClass(yr, model, make);

    myCar.testDrive();

    return 0;
}
