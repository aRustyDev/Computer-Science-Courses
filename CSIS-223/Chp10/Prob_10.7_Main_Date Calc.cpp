/*      Title: Date Calc Class | Problem 10.6
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp10/Prob_10.6_Date%20Calc%20Class.cpp
 *
 *      Purpose: Handle dayType Object by using Classes
 *
 * */      //Specifications Block
/*      Notes/To-Do's:
 *
 * */      //Notes / To-Do's Block

#include <iostream>
#include <iomanip>
#include "dayType.h" //dayType Class

using namespace std;

//Main Fn
int main(){

    int daysToMove = 0;
    dayType day = makeDay();
    cout << "Today is " << day.dayName << endl;

    cout << "--Move 'x' Days--\n\tx=:";
    cin >> daysToMove;
    day.addDays(daysToMove);

    day.getYesterday();

    day.getTomorrow();
    return 0;
}
