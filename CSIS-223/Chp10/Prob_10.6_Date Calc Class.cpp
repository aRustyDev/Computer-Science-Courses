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
 *      Purpose: .
 *
 * */
/*      Notes/To-Do's:
 *          'Set Day' Function
 *          'Print Day' Function
 *          'Return Day' Function
 *          'Return Next Day' Function
 *          'Return Previous Day' Function
 *          'Add Days' Function
 *          add appropriate constructors
 *
*/

#include <iostream>

using namespace std;

class dayType{
    public:
        //Constructors
        dayType(string dayName, int julianDate){}//Parameterized - DayName, JulianDate
        dayType(string dayName){}//Parameterized - DayName
        dayType(){}//default
    
        //Accessor Functions
        void getDay(){}
        void printDay(){}
        void getTomorrow(){}
        void getYesterday(){}
    
        //Mutator Functions
        void setDay(){}
        void addDays(int daysAdded){}
    
    private:
        string dayName(){}
};

int main() {
    return 0;
}
