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
 * */      //Specifications Block
/*      Notes/To-Do's:
 *          * Functions for ...
 *              'Set Day'
 *              'Print Day'
 *              'Return Day'
 *              'Return Next Day'
 *              'Return Previous Day'
 *              'Add Days'
 *          * add appropriate constructors
 *
 *          [Q]: Do I need multiple types of constructors besides Default and Full?
 *
 * */      //Notes / To-Do's Block

#include <iostream>

using namespace std;

//Classes
class dayType{
    //Declarations
        public:
            //Constructors - Definitions
            dayType();
                /*  Default Constructor.
                 *
                 *  Sets the Default Value of dayName & julianDate
                 *
                 *  Default Values
                 *      dayName = "Monday"
                 *      julianDate = 1
                 *
                 *  Post-Condition:
                 *      dayName = "Monday"
                 *      julianDate = 1
                 *
                *///default
            dayType(string);
                /*  Parameterized Constructor. | DayName, JulianDate
                 *
                 *  Sets the Default Value of dayName & julianDate
                 *
                 *  Default Values
                 *      julianDate = 1 (Default)
                 *
                 *  Post-Condition:
                 *      dayName = string
                 *      julianDate = 1  (Default)
                 *
                *///Parameterized - DayName
            dayType(string, int);
                /*  Parameterized Constructor. | DayName, JulianDate
                 *
                 *  Sets the Default Value of dayName & julianDate
                 *
                 *  Post-Condition:
                 *      dayName = string
                 *      julianDate = int
                 *
                *///Parameterized - DayName, JulianDate

            //Accessor Functions - Definitions
            string getDay();
                /*  Function to return the current dayType Objects dayName value.
                 *
                 *  Post-Condition:
                 *
                */
            void printDay();
                /*
                 *
                */
            void getTomorrow();
                /*
                 *
                */
            void getYesterday();
                /*
                 *
                */

            //Mutator Functions - Definitions
            void setDay();
                /*
                 *
                */
            void addDays(int daysAdded);
                /*
                 *
                */

        private:
            //Class Variables - Definitions
            int julianDate;
                /*
                 *
                */
            string dayName;
                /*
                 *
                */
};

//Constructors - Implementations
    dayType::dayType(){
    dayName = "Monday";
    julianDate = 1;
}//default
    dayType::dayType(string dayName){
        this->dayName = dayName;
        julianDate = 1;
    }//Parameterized - DayName
    dayType::dayType(string dayName, int julianDate){
    this->dayName = dayName;
    this->julianDate = julianDate;
}//Parameterized - DayName, JulianDate

//Functions - Implementations
    //Accessor Functions
    string dayType::getDay(){
        return this->dayName;
    }
    void dayType::printDay(){}
    void dayType::getTomorrow(){}
    void dayType::getYesterday(){}

    //Mutator Functions
    void dayType::setDay(){}
    void dayType::addDays(int daysAdded){}

//Main Fn
int main(){

    return 0;
}
