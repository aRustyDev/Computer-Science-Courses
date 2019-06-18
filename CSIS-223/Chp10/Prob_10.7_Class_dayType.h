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

//Global Variables
int dayOffset = 0;//Used to offset the dates if Jan 1 != Monday, Default is Monday (0)

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
//Processor Functions
string dayType::julianToString(){
    int temp = this->julianDate + dayOffset;
    switch (temp % 7){
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
    }
}
int dayType::dayToJulian(){
    int julian = dayOffset ;//Would relate to offset.
    if(this->dayName == "Sunday" || this->dayName == "SUN"){            return 7;
    }else if(this->dayName == "Monday" || this->dayName == "MON"){      return 1;
    }else if(this->dayName == "Tuesday" || this->dayName == "TUE"){     return 2;
    }else if(this->dayName == "Wednesday" || this->dayName == "WED"){   return 3;
    }else if(this->dayName == "Thursday" || this->dayName == "THU"){    return 4;
    }else if(this->dayName == "Friday" || this->dayName == "FRI"){      return 5;
    }else if(this->dayName == "Saturday" || this->dayName == "SAT"){    return 6;
    }
}//Not sure how to include dayOffset Here.

//Accessor Functions
void dayType::printDay(){
    printf("Val of dayType: ");
    cout << this->dayName << endl;
}
dayType* dayType::getDay(){
    return this;
}
dayType dayType::getTomorrow(){
    dayType day = dayType();
    day.setDay(this->dayName);
    day.setJulian(day.dayToJulian());

    day.julianDate = day.julianDate + 1;
    day.dayName = day.julianToString();
    printf("Tomorrow:\n\t");
    day.printDay();
    return day;
}
dayType dayType::getYesterday(){
    dayType day = dayType();
    day.setDay(this->dayName);
    day.setJulian(day.dayToJulian());

    day.julianDate = day.julianDate - 1;
    day.dayName = day.julianToString();
    printf("Yesterday:\n\t");
    day.printDay();
    return day;
}

//Mutator Functions
void dayType::setDay(string day = "Monday"){
    this->dayName = day;
}
void dayType::setJulian(int julian = 1){
    this->julianDate = julian;
}
void dayType::addDays(int daysAdded){
    this->julianDate = this->julianDate + daysAdded;
    this->dayName = this->julianToString();
    printf("\n%d Day's From Today:\n\t", daysAdded);
    this->printDay();
}

//Input Functions
dayType makeDay(){

    //Variables
    string dayAbrv;

    //Input
    printf("MON | TUE | WED | THU | FRI | SAT | SUN\n");
    printf("Enter 3 letter abbreviation of day: ");

    if(cin.peek() == '\n'){
        getline(cin.ignore(), dayAbrv);
    }else {
        getline(cin, dayAbrv);
    }

    //Processing
    for(int i = 0; i < dayAbrv.size(); i++){
        if (!isalpha(dayAbrv[i])){
            cout << "Input Error: isAlpha Catch" << endl;
            break;
        }
        dayAbrv[i] = toupper(dayAbrv[i]);
    }

    dayType day = dayType();            //Make new Obj
    day.setDay(dayAbrv);                //Set Obj.string = input
    day.setJulian(day.dayToJulian());   //Use Obj.string to set Obj.Int = 'correct Int'
    day.setDay(day.julianToString());   //Use Corrected Obj.Int to get full Obj.string.

    //Output
    return day;

}

#endif //PROB10_7_DATECLASS_DAYTYPE_H
