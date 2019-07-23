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

#ifndef PROB14_04_TIMEFORMAT_H
#define PROB14_04_TIMEFORMAT_H

// C++ program to convert 12 hour to 24 hour format

#include<iostream>
using namespace std;

class timeFormat
{
    timeFormat();

public:
    //Variables
    int hour, min, sec;

    //Declaration Functions
    //Post-condition: sets the local variable passed through
    int setHH(int HH);
    int setMM(int MM);
    int setSS(int SS);

    //Processing Functions
    //Post-condition: Calls the Error Handlers.
    void convert24(int, int, int, string);
    //Post-condition: Prints the time currently stored in local variables
    void printTime();

    //Error Handling Functions
    //Post-condition: Checks the given variables for errors.
    void checkHH(int hour, string meridian);
    void checkMM(int min);
    void checkSS(int sec);
};

int timeFormat::setHH(int HH){
    this->hour = HH;
}
int timeFormat::setMM(int MM){
    this->min = MM;
}
int timeFormat::setSS(int SS){
    this->sec = SS;
}
void timeFormat::checkHH (int hour, string meridian){
    while(true) {
        cout << typeid(hour).name() << endl;
        try {
            if ((hour < 12 && hour > 0) && (meridian == "PM" || meridian == "Pm" || meridian == "pm" || meridian == "pM")) {//If its in the Afternoon
                setHH(hour + 12);
                break;
            }else if ((hour < 13 && hour > 0) && (meridian == "AM" || meridian == "Am" || meridian == "am" || meridian == "aM")) {//If its in the Morning
                setHH(hour);
                break;
            }else if ((hour == 12) && (meridian == "PM" || meridian == "Pm" || meridian == "pm" || meridian == "pM")) {//If its Midnight
                setHH(0);
                break;
            }else{//If none of the above, its an error, figure out which
                cin.clear();
                cin.ignore();
                throw hour;
            }

        }catch (int c) {
            cout << "Input value '" << hour << "' is not valid"<< endl;
            cout << "::Detected Var Type Int::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Hour (HH): ";
            cin >> hour;
            cout << "AM or PM: ";
            cin >> meridian;
            checkHH(hour,meridian);
        }catch(char c) {
            cout << "Input value '" << hour << "' is not valid"<< endl;
            cout << "::Detected Var Type Char::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Hour (HH): ";
            cin >> hour;
            cout << "AM or PM: ";
            cin >> meridian;
            checkHH(hour,meridian);
        }catch (string c) {
            cout << "Input value '" << hour << "' is not valid"<< endl;
            cout << "::Detected Var Type String::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Hour (HH): ";
            cin >> hour;
            cout << "AM or PM: ";
            cin >> meridian;
            checkHH(hour,meridian);
        }catch (double c) {
            cout << "Input value '" << hour << "' is not valid"<< endl;
            cout << "::Detected Var Type Double::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Hour (HH): ";
            cin >> hour;
            cout << "AM or PM: ";
            cin >> meridian;
            checkHH(hour,meridian);
        }
    }
}
void timeFormat::checkMM (int min){
    while(true) {
        try {
            if (min < 60 && min >= 0) {//If its within the limits of an hour
                setMM(min);
                break;
            }else{//Else, its an error, figure out which
                cin.clear();
                cin.ignore();
                throw min;
            }

        }catch (int c) {
            cout << "Input value '" << min << "' is not valid"<< endl;
            cout << "::Detected Var Type Int::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Minute (MM): ";
            cin >> min;
            checkMM(min);
        }catch (char c) {
            cout << "Input value '" << min << "' is not valid"<< endl;
            cout << "::Detected Var Type Char::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Minute (MM): ";
            cin >> min;
            checkMM(min);
        }catch (string c) {
            cout << "Input value '" << min << "' is not valid"<< endl;
            cout << "::Detected Var Type String::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Minute (MM): ";
            cin >> min;
            checkMM(min);
        }catch (double c) {
            cout << "Input value '" << min << "' is not valid"<< endl;
            cout << "::Detected Var Type Double::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Minute (MM): ";
            cin >> min;
            checkMM(min);
        }
    }
}
void timeFormat::checkSS(int sec){
    while(true) {
        try {
            if (sec < 60 && sec >= 0) {//If its within the limits of a Minute
                setSS(sec);
                break;
            }else{//Else, its an error, figure out which
                cin.clear();
                cin.ignore();
                throw sec;
            }

        }catch (int c) {
            cout << "Input value '" << sec << "' is not valid"<< endl;
            cout << "::Detected Var Type Int::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Second (SS): ";
            cin >> sec;
            checkSS(sec);
        }catch (char c) {
            cout << "Input value '" << sec << "' is not valid"<< endl;
            cout << "::Detected Var Type Char::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Second (SS): ";
            cin >> sec;
            checkSS(sec);
        }catch (string c) {
            cout << "Input value '" << sec << "' is not valid"<< endl;
            cout << "::Detected Var Type String::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Second (SS): ";
            cin >> sec;
            checkSS(sec);
        }catch (double c) {
            cout << "Input value '" << sec << "' is not valid"<< endl;
            cout << "::Detected Var Type Double::" << endl;
            cout << "::Input must be whole Int between 1 & 12 Inclusive::" << endl;
            cout << "Second (SS): ";
            cin >> sec;
            checkSS(sec);
        }
    }
}
void timeFormat::printTime(){
    cout << "Your time converted: " << hour << ":" << min << ":" << sec;
}

void timeFormat::convert24(int hr, int mn, int sc, string meridian)
{
    checkHH(hr, meridian);
    checkMM(mn);
    checkSS(sc);
}
#endif //PROB14_04_TIMEFORMAT_H
