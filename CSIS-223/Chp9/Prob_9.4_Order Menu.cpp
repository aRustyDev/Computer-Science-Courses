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
/*      Notes:
 *          Still need to get multiple word selections to be accepted
 *          Still need to Format the Menu Output to align
 *              wtf is going wrong with setw()?
 *          Find way to add/remove menu items
 *          Write a putback function
 *          Set Main to clear screen and reload menu everytime they make another selection
 *          Make the entries more forgiving
 *              force capitalize entries, allow spaces, check for invalid entries.
 *
 *
 *
*/

#include <iostream>
#include <array>
#include <string>
#include <map>
#include <vector>

using namespace std;

//Structures
struct menuItemType{
    string menuItem;
    double menuPrice;
};

//Global Variables
map<string, int> qtyMap{ { "Plain Egg", 0 },
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
void displayMenu(){
    printf("\n:::Welcome to Adam's Eatery:::\n\n"
           "Please choose from our wonderful selection\n"
           "- - - - - - - - - - - - - - - - - - - - - - -\n");

    for (auto const& x : priceMap){
        string key = x.first;
        double val = x.second;
        cout << key << "\t\t$" <<  val << endl;// string's value
    }
}
bool checkOrderList(string order){
    if (find(begin(orderList), end(orderList), order) == end(orderList)){
        return true;
    }else{
        return false;
    }
}
menuItemType getItem(string order){
    menuItemType item;
    item.menuItem = order;
    item.menuPrice = priceMap[order];
    return item;
}
double updateTab(){
    //Itr through OrderList, Add (Qty*ItemPrice) to Tab Total
    auto iter = orderList.begin();
    double tab = 0;
    for ( ; iter !=  orderList.end(); iter++){
        //Tab = Tab + (Price * Qty)
        tab = tab + (priceMap[(*iter).menuItem] * (*iter).menuPrice);
    }
    return tab;
}
double order(double tab){
    //get Order
    string order;
    cin >> order;

    if (true){//verify the selection is valid.
        //priceMap.find(order) != priceMap.end()

        if(!checkOrderList(order)){//if selection is new, add to OrderList
            orderList.push_back( getItem(order) );
        }
        qtyMap[order] = qtyMap[order] + 1;

    }else{
        cout << "Im Sorry, but we don't serve " << order << " here" << endl;
    }
    printf("Current Tab: $%.2F", (tab));

    tab = updateTab();
    return tab;
}

int main() {
    double tab = 0;
    bool ordering = true;
    char answer;

    displayMenu();
    while (ordering == true){
        tab = order(tab);
        cout << "\nWould you like anything else?\t\ny/n: ";
        cin >> answer;
        if(answer == 'N'){
            ordering = false;
        }
    }

    tab = updateTab();
    cout << "Your Total Today is...\n\t$" << tab;

    return 0;
}
