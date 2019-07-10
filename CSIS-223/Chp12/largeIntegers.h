//
// Created by Adam Smith on 2019-07-03.
//

#ifndef PROB12_02_LARGEINTEGERS_H
#define PROB12_02_LARGEINTEGERS_H

using namespace std;

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

class largeIntegers{
    //Variables
        //Dynamic Length Var
        int bigIntLength;

        //Dynamic Array Variables
        char *dBigChar;
        string dStr;

    //Constructors
    largeIntegers();
    largeIntegers(string);

    //mutators
    void setBigIntLength(string);
    void set_bigChar(string);
    void set_str(string);

    //accessors
    largeIntegers get_INTEGER_LENGTH();
    largeIntegers get_dInteger_Array();
    largeIntegers get_dInteger_Int();

    //processors
    largeIntegers add(largeIntegers, largeIntegers);
    largeIntegers sub(largeIntegers, largeIntegers);
    largeIntegers mult(largeIntegers, largeIntegers);
    largeIntegers compare(largeIntegers, largeIntegers);
};

largeIntegers::largeIntegers(){
    setBigIntLength("");
    set_str("");
    dBigChar = new char[bigIntLength];
    set_bigChar("");
}
largeIntegers::largeIntegers(string bigInt1){
    setBigIntLength(bigInt1);
    set_str(bigInt1);
    dBigChar = new char[bigIntLength];
    set_bigChar(bigInt1);
}

void largeIntegers::setBigIntLength (string bigIntStr) {
    int tmp = bigIntStr.length();
    if(bigIntLength < tmp){
        bigIntLength = tmp;
    }
}
void largeIntegers::set_bigChar (string bigIntStr) {
    int i = 0;
    for(char& c : bigIntStr) {
        this->dBigChar[i] = c;
        i++;
    }
}
void largeIntegers::set_str(string str){
        dStr = str;
    }
void reverse(char arr[]){
        int n;
        n = sizeof(arr) / sizeof(arr[0]);
        reverse(arr, arr + n);
    }

largeIntegers largeIntegers::add(largeIntegers ref, largeIntegers dif){
    char *bigIntOut;
    bigIntOut = new char[bigIntLength];

    reverse(ref.dBigChar);//Reverse the CharArr's to work w/
    reverse(dif.dBigChar);

    int i = 0;
    int carry = 0;
    for(char& c : ref.dStr){
        int sum = c + dif.dBigChar[i] + carry;
        carry = 0;
        bigIntOut[i] = sum;
        i++;
        if(sum%10 == sum){ continue;}else{carry = 1;}
    }

    reverse(ref.dBigChar);//undo Reverse
    reverse(dif.dBigChar);

    string strOut(bigIntOut);
    delete [] bigIntOut;
    return largeIntegers(strOut);
};
largeIntegers largeIntegers::sub(largeIntegers ref, largeIntegers dif){
    char *bigIntOut;
    bigIntOut = new char[bigIntLength];

    reverse(ref.dBigChar);//Reverse the CharArr's to work w/
    reverse(dif.dBigChar);

    int i = 0;
    int carry = 0;
    for(char& c : ref.dStr){
        int sum = c - dif.dBigChar[i] + carry;
        carry = 0;
        if(sum < 0){ carry = sum; sum += 10;}
        bigIntOut[i] = sum;
        i++;
    }

    reverse(ref.dBigChar);//undo Reverse
    reverse(dif.dBigChar);

    string strOut(bigIntOut);
    delete [] bigIntOut;
    return largeIntegers(strOut);
};
largeIntegers largeIntegers::mult(largeIntegers ref, largeIntegers dif){
    string *sumArr;
    string *tmpArr;
    largeIntegers sumOrig;
    sumArr = new string[bigIntLength];

    int exp1 = 0;
    bool first = true;
    int i = 0;

    for(char& c1 : ref.dStr){
        int exp2 = 0;
        for(char& c2 : dif.dStr){
            if(first == true){
                sumOrig = largeIntegers(to_string(ref.dBigChar[c1] * dif.dBigChar[c2] * pow(10, exp1) * pow(10, exp2)));
                first = false;
            }else {
                largeIntegers tmpBigInt = largeIntegers(to_string(ref.dBigChar[c1] * dif.dBigChar[c2] * pow(10, exp1) * pow(10, exp2)));
                sumOrig = add(sumOrig, tmpBigInt);
            }
            exp2++;
            i++;
        }
        exp1++;
    }

    reverse(ref.dBigChar);//undo Reverse
    reverse(dif.dBigChar);

    delete [] sumArr;
    delete [] tmpArr;

    return sumOrig;
};
largeIntegers largeIntegers::compare(largeIntegers ref, largeIntegers dif){
    int x = ref.dStr.length();
    int y = dif.dStr.length();
    if(x != y){
        if(x > y){
            return ref;
        }else{
            return dif;
        }
    }
    int i = 0;
    for(char& c1 : ref.dStr){
        if(ref.dBigChar[c1] == dif.dBigChar[i]){
            continue;
        }else if(ref.dBigChar[c1] > dif.dBigChar[i]){
            return ref;
        } else if (ref.dBigChar[c1] < dif.dBigChar[i]) {
            return dif;
        }
    }
};


#endif //PROB12_02_LARGEINTEGERS_H
