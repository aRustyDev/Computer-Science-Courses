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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp9/Prob_9.4_Order%20Menu.cpp
 *
 *      Purpose: Take the Users 'order' and return the final cost of the order.
 *
 * */
/*      Notes/To-Do's:
 *          Find way to add/remove menu items
 *          Write a putback function
 *          Check continue ordering Char for error, and provide correction.
 *
 *
 *
*/

#include <iostream>
#include <array>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

//Structures
struct menuItemType{
    string menuItem;
    double menuPrice;
};

//Global Variables
map<string, double> qtyMap{ { "Plain Egg", 0 },
                          { "Bacon & Egg", 0 },
                          { "Muffin", 0 },
                          { "French Toast", 0 },
                          { "Fruit Basket", 0 },
                          { "Cereal", 0 },
                          { "Coffee", 0 },
                          { "Tea", 0 }};
map<string, double> priceMap{ { "Plain Egg", 1.45 },
                            { "Bacon & Egg", 2.45 },
                            { "Muffin", 0.99 },
                            { "French Toast", 1.99 },
                            { "Fruit Basket", 2.49 },
                            { "Cereal", 0.69 },
                            { "Coffee", 0.50 },
                            { "Tea", 0.75 }};
vector <menuItemType> orderList = {};

//Function Overloading

//Functions Definitions
void buildOrderList(){
    map <string, double>::iterator it = priceMap.begin();
    for (map<string, double>::iterator it = priceMap.begin(); it != priceMap.end(); ++it){
        menuItemType *item = new menuItemType;
        item->menuItem = it->first;
        item->menuPrice = it->second;
    }
}
void displayMenu(){
    printf("\n:::Welcome to Adam's Eatery:::\n\n"
           "Please choose from our wonderful selection\n"
           "- - - - - - - - - - - - - - - - - - - - - - -\n");

    for (auto const& x : priceMap){
        string key = x.first;
        double val = x.second;
        cout << setw(12) << left << key << fixed << setprecision(2) << setw(4) << right << "$" <<  val << endl;// string's value
    }
}
double updateTab(){
    //Itr through OrderList, Add (Qty*ItemPrice) to Tab Total
    auto iter = orderList.begin();
    double tab = 0;

    for (map<string, double>::iterator iter = priceMap.begin(); iter != priceMap.end(); ++iter){
        //Tab = Tab + (Price * Qty)
        tab = tab + (priceMap[(*iter).first] * qtyMap[(*iter).first]);
    }
    return tab;
}
double order(double tab){
    //get Order
    string order;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -\nOrder: ";
    if(cin.peek() == '\n'){
        getline(cin.ignore(), order);
    }else {
        getline(cin, order);
    }
    order[0] = toupper(order[0]);
    for(int i = 1; i < order.size(); i++){
        if ( isspace(order[i-1]) && isalpha(order[i]) ){
            order[i] = toupper(order[i]);
        }
    }

    if (priceMap.find(order) != priceMap.end()){//verify the selection is valid.

        qtyMap[order] = qtyMap[order] + 1;

    }else{
        cout << "Im Sorry, but we don't serve " << order << " here\n"
             << "- - - - - - - - - - - - - - - - - - - - - - -";
    }

    tab = updateTab();
    printf("Current Tab: $%.2F", (tab));

    order.clear();
    return tab;
}

int main() {
    double tab = 0;
    bool ordering = true;
    char answer;

    buildOrderList();
    displayMenu();
    while (ordering == true){
        tab = order(tab);
        cout << "\n\n\nWould you like anything else?\n\ty/n: ";
        cin >> answer;
        if(toupper(answer) == 'N'){
            ordering = false;
        }
    }

    tab = updateTab();
    cout << "Your Total Today is...\n\t$" << tab;

    return 0;
}
