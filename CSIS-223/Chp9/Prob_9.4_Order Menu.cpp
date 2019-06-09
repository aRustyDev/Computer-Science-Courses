/*      Title: Order from the Menu | Problem 9.4
 *      Author: Adam C Smith | RedGrinGrumbler
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
 *       GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp9/Prob_9.4_Order%20Menu.cpp
 *
 *      Purpose:
 *
 * */
/*      Notes:
 *
 *
 *
*/

#include <iostream>
#include <array>
#include <string>
#include <map>
#include <sstream>
using namespace std;

//Structures
struct menuItemType{
    string menuItem;
    double menuPrice;
};

//Global Variables
int menuSize = 8;
menuItemType *menuPtr = new menuItemType[menuSize];
map<string, double> menu{ { "Plain Egg", 1.45 },
                        { "Bacon & Egg", 2.45 },
                        { "Muffin", 0.99 },
                        { "French Toast", 1.99 },
                        { "Fruit Basket", 2.49 },
                        { "Cereal", 0.69 },
                        { "Coffee", 0.50 },
                        { "Tea", 0.75 }};

//Functions
void buildMenu(){

};//Future Requirement
void displayMenu(){
    printf(":::Welcome to Adam's Eatery:::\n\n"
           "Please choose from our wonderful selection\n"
           "- - - - - - - - - - - - - - - - - - - - - - -");
    for (auto const& x : menu){
        cout << x.first  // string (key)
             << '\t'
             << x.second   // string's value
             << endl;
    }
}
void order(double tab){
    double item = 0;
    string order;
    cin >> order;
    item = menu[order];
    tab = tab + item;
}
double getTheCheck(double tab){
    double check = tab;
    tab = 0;
    return check;
}

int main() {
    double tab = 0;

    displayMenu();





    printf( "a%d\n"
            "b%d\n"
            "c%d\n", 1,2,3);

    return 0;
}
