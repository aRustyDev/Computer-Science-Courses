#include <iostream>
#include "carClass.h"

using namespace std;

int main () {

    string yr, model, make;

    cout << "\nVehicle Year: ";
    cin >> yr;
    cout << "Vehicle Make: ";
    cin >> make;
    cout << "Vehicle Model: ";
    cin >> model;

    carClass myCar = carClass(yr, model, make);

    myCar.testDrive();

    return 0;
}
