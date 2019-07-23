//
// Created by Adam Smith on 2019-07-22.
//

#ifndef FINALPROJECT_PROB01_CARCLASS_H
#define FINALPROJECT_PROB01_CARCLASS_H

#include <iostream>

using namespace std;

class carClass{

    public:
        //Variables
        string yearModel;
        string make;
        int speed;

        //Constructors
        carClass(string, string, string);

        //Accessor Functions
        int getSpeed();
        string getMake();
        string getYrModel();

        //Mutator Functions
        void setYrModel(string, string);
        void setMake(string);
        void accelerate();
        void brake();
        void testDrive();

};
carClass::carClass(string yr, string model, string make){
    this->speed = 0;
    setMake(make);
    setYrModel(yr, model);
}

int carClass::getSpeed(){
    return this->speed;
}
string carClass::getMake(){
    return this->make;
}
string carClass::getYrModel(){
    return this->yearModel;
}

void carClass::setYrModel(string yr, string model){
    this->yearModel = yr + " " + model;
}
void carClass::setMake(string make){

    this->make = make;
}

void carClass::accelerate(){
    this->speed +=5;
}
void carClass::brake(){
    this->speed -=5;
}
void carClass::testDrive() {
    cout << "\n::Current Car:: ";
    cout << "\nMake: ";
    cout << this->getMake();
    cout << "\nModel: ";
    cout << this->getYrModel() << endl;
    for(int i = 0; i < 5; i++){
        this->accelerate();
        cout << "\nCurrent Speed: ";
        cout << this->getSpeed() << " MPH";
    }
    for(int i = 0; i < 5; i++){
        this->brake();
        cout << "\nCurrent Speed: ";
        cout << this->getSpeed() << " MPH";
    }
}

#endif //FINALPROJECT_PROB01_CARCLASS_H
