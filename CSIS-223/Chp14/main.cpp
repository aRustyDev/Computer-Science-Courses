/*      Title: timeFormat.h | Problem 14.04
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp14
 *
 *      Purpose: Define the Class for timeFormat & its exception handlers.
 *
 */
 
#include <iostream>
#include "timeFormat.h"
#include <string>

// Driver code
int main()
{
    timeFormat convert;
    int hr, mn, sc = 0;
    string meridian;

    cout << "Please input hours in 12 hr notation: ";
    cin >> hr;
    cout << "Please input minutes: ";
    cin >> mn;
    cout << "Please input seconds: ";
    cin >> sc;
    cout << "AM or PM: ";
    cin >> meridian;


    convert.convert24(hr, mn, sc, meridian);
    convert.printTime();

    return 0;

}
