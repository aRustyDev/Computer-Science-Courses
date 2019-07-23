//
// Created by Adam Smith on 2019-07-22.
//

#ifndef PROB15_02_DIAMONDPATTERN_H
#define PROB15_02_DIAMONDPATTERN_H

#include <iostream>

using namespace std;

void printDiamond(int count, int num){
    int i = num;
    while(i > count){
        cout << " ";
        i--;
    }
    for(int j = 0; j < i; j++){
        cout << "x ";
    }
    cout << "\n";
    if (count < num) printDiamond(count + 1, num);
    for(int j = num + 1; j > i; j--){
        cout << " ";
    }
    for(int j = 1; j < i; j++){
        cout << "x ";
    }
    cout << "\n";

}

#endif //PROB15_02_DIAMONDPATTERN_H
