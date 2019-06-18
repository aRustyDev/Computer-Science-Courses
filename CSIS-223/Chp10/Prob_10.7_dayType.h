// 
// Created by Adam Smith on 2019-06-17.
//

#ifndef PROB10_7_DATECLASS_DAYTYPE_H
#define PROB10_7_DATECLASS_DAYTYPE_H

#include <string>
using namespace std;

//Classes
class dayType{
    //Declarations
public:
    //Constructors - Definitions
    dayType();
    /*  Default Constructor.
     *
     *  Creates dayType Object with Default Value of dayName & julianDate
     *
     *  Post-Condition:
     *      dayName = "Monday"
     *      julianDate = 1
     *
    *///default
    dayType(string);
    /*  Parameterized Constructor. | DayName, JulianDate
     *
     *  Creates dayType Object with & sets Value of dayName & julianDate
     *
     *  Post-Condition:
     *      dayName = string
     *      julianDate = 1  (Default)
     *
    *///Parameterized - DayName
    dayType(string, int);
    /*  Parameterized Constructor. | DayName, JulianDate
     *
     *  Creates dayType Object with & sets Value of dayName & julianDate
     *
     *  Post-Condition:
     *      dayName = string
     *      julianDate = int
     *
    *///Parameterized - DayName, JulianDate

    //Accessor Functions - Definitions
    void printDay();
    /*  Function that will print this->dayName
     *
     *  Post-Condition:
     *      cout << Val of dayType: this->dayName
     *
    */
    dayType* getDay();
    /*  Function to return a pointer to the current dayType Objects dayName value.
     *
     *  Post-Condition:
     *      return this;
     *
    */
    dayType getTomorrow();
    /*  Function that returns a new dayType object, incremented by 1 day from the input
     *
    */
    dayType getYesterday();
    /*  Function that returns a new dayType object, decremented by 1 day from the input
     *
    */

    //Mutator Functions - Definitions
    void setDay(string);
    /*  Function to change the dayType Objects Day Name
     *
     *  Post-Condition:
     *      this->dayName = day;
     *
    *///
    void setJulian(int);
    /*  Function to set a dayType Objects Julian Val
     *
     *  Post-Condition:
     *      this->julianDate = julian;
     *
    *///
    void addDays(int daysAdded);
    /*  Function adds INT days to current julianDate Value
     *
     *  Post-Condition:
     *       this->julianDate = this->julianDate + daysAdded;
     *       this->dayName = this->julianToString();
     *
    */
    //Processor Functions
    string julianToString();
    /*  Function Syncronizes Day Name to the Julian Day Val
     *
     *  Post-Condition:
     *       this->dayName = String("correct weekday");
     *
    */
    int dayToJulian();
    /*  Function Syncronizes Julian Day to the Day Name Val
     *
     *  Post-Condition:
     *       this->julianDay = Int(Correct Number);
     *
    */

    //variables
    int julianDate;
    /*  Int Variable that holds the Julian Date
     *
    */
    string dayName;
};

#endif //PROB10_7_DATECLASS_DAYTYPE_H
