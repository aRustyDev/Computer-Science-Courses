/*      Title: memberType Class | Problem 10.13
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp10/Prob_10.13_Member%20Type%20Class.h
 *
 * */      //Specifications Block

#ifndef PROB10_13_MEMBERTYPE_MEMBERTYPE_H
#define PROB10_13_MEMBERTYPE_MEMBERTYPE_H

#include <string>
using namespace std;

//Classes
class memberType{
    //Declarations
    public:
        //Constructors - Definitions
        memberType();/*  Default Constructor.
         *
         *  Creates dayType Object with Default Value of dayName & julianDate
         *
         *  Post-Condition:
         *      firstName = "John";
         *      lastName = ""Doe;
         *      personName = firstName + lastName;
         *      memberID = "12345";
         *      purchaseAmt = 0;
         *      bookCnt = 0;
         *
        *///default
        memberType(string, string);/*  Parameterized Constructor. | DayName, JulianDate
         *
         *  Creates dayType Object with & sets Value of dayName & julianDate
         *
         *  Post-Condition:
         *      firstName = fName;
         *      lastName = lName;
         *      personName = firstName + lastName;
         *      memberID = "12345";
         *      purchaseAmt = 0;
         *      bookCnt = 0;
         *
        *///Parameterized - personName
        memberType(string, string, string);/*  Parameterized Constructor. | DayName, JulianDate
         *
         *  Creates dayType Object with & sets Value of dayName & julianDate
         *
         *  Post-Condition:
         *      firstName = fName;
         *      lastName = lName;
         *      personName = firstName + lastName;
         *      memberID = ID;
         *      purchaseAmt = 0;
         *      bookCnt = 0;
         *
        *///Parameterized - personName, memberID

        //Accessor Functions - Definitions
        void printName(); /*  Function that will print this->personName
         *
         *  Post-Condition:
         *      cout << Val of memberType: this->personName
         *
        */
        void printMember();/* Function to print all vars of this->memberType
        *
        *   Post-Condition:
        *       cout << this->personName ;
        *       cout << this->memberID ;
        *       cout << this->cart[] ;
        *       cout << this->purchaseAmt ;
        *       cout << total ;
        */
        void printCart();/*  Function that will print this->personName
         *
         *  Post-Condition:
         *      cout << this->purchaseAmt << this->bookCnt << endl;
         *
        */
        memberType* getMember();/*  Function to return a pointer to the current memberType Object.
         *
         *  Post-Condition:
         *      return this;
        */

        //Mutator Functions - Definitions
        void setName(string fName, string lName);/*
         *  Function to set the Var Name of memberType Object
         *
         *  Post-Condition:
         *      string name = fName + " " + lName;
         *      this->personName = name;
         *
        */
        void setMemberID();/*
        *
        */
        void changeName(string);/*
        *  Function to set the Var Name of memberType Object
        *
        *  Post-Condition:
        *       string old = this->personName;
        *       this->personName.clear();
        *       this->personName = newName;
        *
        */
        void buyBook(double, string, int);/*
         *  Function to add a book to the cart
         *
         *  Post-Condition:
         *      this->bookCnt += qty;
         *      this->purchaseAmt += cost;
        */
        void putbackBook(double, string, int);/*
         *  Function to remove a book from the cart
         *
         *  Post-Condition:
         *      this->bookCnt -= qty;
         *      this->purchaseAmt -= cost;
        */

        //variables
        string firstName;
        string lastName;
        string personName;
        string memberID;
        double purchaseAmt;
        int bookCnt;
};

//Constructors - Implementations
    memberType::memberType(){
        firstName = "John";
        lastName = "Doe";
        personName = firstName + lastName;
        memberID = "12345";
        purchaseAmt = 0;
        bookCnt = 0;
    };//default
    memberType::memberType(string fName, string lName){
        firstName = fName;
        lastName = lName;
        personName = firstName + lastName;
        memberID = "12345";
        purchaseAmt = 0;
        bookCnt = 0;
    };//Parameterized - personName
    memberType::memberType(string fName, string lName, string ID){
        firstName = fName;
        lastName = lName;
        personName = firstName + lastName;
        memberID = ID;
        purchaseAmt = 0;
        bookCnt = 0;
    };//Parameterized - personName, memberID

//Functions - Implementations
    //Accessor Functions
        void memberType::printName(){
            cout << this->personName << endl;
        };
        void memberType::printMember(){
            cout << this->personName << endl;
            cout << this->memberID << endl;
        };
        void memberType::printCart(){
            cout << "::Total::----::Qty::" << endl;
            cout << this->purchaseAmt << this->bookCnt << endl;
        };
        memberType* memberType::getMember(){
            return this;
        };

    //Mutator Functions
        void memberType::setName(string fName, string lName){
            string name = fName + " " + lName;
            this->personName = name;
        };
        void memberType::setMemberID () {
            int ID = rand() % 99999 + 10000;
            this->memberID = to_string(ID);
        }
        void memberType::changeName(string name){
            string old = this->personName;
            this->personName.clear();
            this->personName = name;
        };
        void memberType::buyBook(double cost, string title, int qty = 1){
            this->bookCnt += qty;
            this->purchaseAmt += cost * qty;
        };
        void memberType::putbackBook(double cost, string title, int qty = 1){
            this->bookCnt -= qty;
            this->purchaseAmt -= cost * qty;
        };

    //Processor Functions

#endif //PROB10_13_MEMBERTYPE_MEMBERTYPE_H
