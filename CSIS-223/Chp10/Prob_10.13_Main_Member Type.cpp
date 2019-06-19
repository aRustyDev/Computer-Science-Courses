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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp10/Prob_10.13_Main_Member%20Type.cpp
 *
 *      Purpose:
 *
 * */      //Specifications Block
/*      Notes/To-Do's:
 *
 * */      //Notes / To-Do's Block

#include <iostream>
#include <iomanip>
#include "memberType.h" //dayType Class
#include <map>

using namespace std;

//Main Fn
int main(){

    string first;
    string last;
    int ID;
    char ans[] = {}; //stringsream
    bool check = true;

    map<string, double> bookshelf = {   {"book1", 1.20},
                                        {"book2", 2.25},
                                        {"book3", 3.45},
                                        {"book4", 1.50},
                                        {"book5", 3.00}};

    memberType person = memberType();

    //Build initial MemberType Object
    cout << "First Name: ";
    cin >> first;
    cout << "Last Name: ";
    cin >> last;
    person.setName(first,last);
    while(check == true) {
        cout << "\nDo you have a Member ID? (y/n) : ";
        cin >> ans[0];
        if (isalpha(ans[0]) != true) {
            cout << "\nInput is invalid, please enter 'y' or 'n'" << endl;
            continue;
        }else{
            if (toupper(ans[0]) == 'Y'){
                cout << "Member ID: ";
                cin >> ID;
                person.memberID = to_string(ID);
            }else{
                person.setMemberID();
            }
            check = false;
            continue;
        }
    }

    //Add to MemberTypes "Cart"
    check = true;
    bool check2 = true;
    ans[0] = 'a';
    string title;
    int qty;

    while(check == true){
        title.clear();
        cout <<"\nWould you like to view the selection? :(y/n): ";
        cin >> ans[0];
        if (isalpha(ans[0]) != true) {
            cout << "\nInput is invalid, please enter 'y' or 'n'" << endl;
            continue;
        }else{
            while(check2 == true) {
                title.clear();
                if (toupper(ans[0]) == 'Y') {//Print BookShelf IF theyre ordering
                    cout << "Enter the title of the book you want" << endl;
                    cout << " :: Title ::   :: Price ::" << endl;
                    for (map<string, double>::iterator it = bookshelf.begin(); it != bookshelf.end(); ++it) {
                        cout << "\t" << setw(8) << left
                             << it->first << "\t $"
                             << setw(8) << setprecision(2) << fixed
                             << it->second << endl;
                    }
                } else { //ELSE say goodbye
                    cout << "Thank you for your business" << endl;
                    check2 = false;
                    check = false;
                    continue;
                }
                cout << "Selection: ";
                cin >> title;//IF they bought...
                if (bookshelf.find(title) == bookshelf.end()) {//Test input
                    cout << "\n:: Input is invalid ::" << endl;
                    continue;
                } else {//IF input good, see how many of that book they bought
                        // & see if they want to buy something else.
                    cout << "\tQty: ";
                    cin >> qty;
                    person.buyBook(bookshelf[title], title, qty);
                    cout << "Would you like to purchase another book? :(y/n): ";
                    cin >> ans[0];

                    if (toupper(ans[0]) != 'Y') {//IF they dont want to buy anything else, goodbye
                        cout << "\n- - - - - - - - - - - - - - ";
                        cout << "\nThank you for your business" ;
                        cout << "\n- - - - - - - - - - - - - - ";
                        check2 = false;
                        check = false;
                        continue;
                    }
                }
            }
        }
    }

    //Outputs
    cout << "\n\n:: Purchase Receipt ::\n";
    cout << "Member Name: " << person.personName << endl;
    cout << "  Member ID: " << person.memberID << endl;
    cout << setprecision(2) << "Total Spent: $" << person.purchaseAmt << endl;
    cout << "Total Books: " << person.bookCnt << endl;

    //Change MemberType Object



    return 0;
}
