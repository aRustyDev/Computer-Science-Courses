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
 *          * Functions for ...
 *              'Set Day'
 *              'Print Day'
 *              'Return Day'
 *              'Return Next Day'
 *              'Return Previous Day'
 *              'Add Days'
 *          * add appropriate constructors
 *          The use of Julian Dates makes for a simple calculator, however it assumes the year start on Monday.
 *          This may not always be true, this can easily be solved by implementing a initial offset for what ever
 *          day the year started on. I have not implemented this because I am not planning on taking this to any
 *          production level.
 *
 *          [Q]: Do I need multiple types of constructors besides Default and Full?
 *
 * */      //Notes / To-Do's Block

#include <iostream>
#include <iomanip>

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
            void printDay();
                /*
     *
    */
            dayType* getDay();
                /*  Function to return the current dayType Objects dayName value.
                 *
                 *  Post-Condition:
                 *
                */
            dayType getTomorrow();
                /*
                 *
                */
            dayType getYesterday();
                /*
                 *
                */

            //Mutator Functions - Definitions
            void setDay(string);
                /*  Function to change the dayType Object
                 *
                 *  Post-Condition:
                 *      dayType Object
                 *      * day value of STRING
                 *      * julian value of INT
                 *
                *///DONE
            void setJulian(int);
            void addDays(int daysAdded);
                /*  Function adds INT days to current julianDate Value
                 *
                 *  Post-Condition:
                 *
                 *
                */
            //Processor Functions
            string julianToString();
            int dayToJulian();

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
        printf("\nToday:\n\t");
        this->printDay();
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
        printf("\nToday:\n\t");
        this->printDay();
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
