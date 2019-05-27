#include <iosstream>
using namespace std;


#include <iostream>
using namespace std;

int compare(char ch_1[],char ch_2[]){
    int i = 0;
    while (true){
        if(ch_1[i] == NULL && ch_2[i] != NULL) return false;
        if(ch_1[i] != NULL && ch_2[i] == NULL) return false;
        if (ch_1[i] == NULL && ch_2[i] == NULL) break;
        if (ch_1[i] != ch_2[i]) return false;
        i += 1;
    }
    return true;
}

int main(){
    char ch[][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","...-","-.--","-..-"};
    int n;
    cout << "Do you want to translate text to Morse code (1) or translate Morse code to text (2)? ";
    cin >> n;
    if (n == 1){
        char str[256];
        cin.getline(str,256);
        cout << "Enter Text Message: ";
        cin.getline(str,256);
        cout << "Morse Code: ";
        for (int i = 0; i < 256; i++){
            if (str[i] == NULL) break;
            if (str[i] == ' ') cout << " ";       // 7 Space between Two words
            else cout << ch[toupper(str[i]) - 65] << " ";   // Morse Code with three Space between two characters
        }
        cout << endl;
    }
    else{
        char str[1000];
        cin.getline(str,100);
        cout << "Enter Morse Code: ";
        cin.getline(str,1000);
        cout << "Text Message : ";
        int j = 0;
        char temp[100];
        int decide = 0;
        for (int i = 0; i < 1000; i++){
            if (str[i] == NULL){
                int res = -1;
                temp[j] = '\0';
                for (int k = 0; k < 26; k++){
                    if (compare(ch[k],temp) == true){
                        res = k;
                        break;
                    }
                }
                cout << (char)(97+res);
                break;
            }
            if (str[i] == ' '){
                int res = -1;
                temp[j] = '\0';
                for (int k = 0; k < 26; k++){
                    if (compare(ch[k],temp) == true){
                        res = k;
                        break;
                    }
                }

                j = 0;
                if (str[i+3] == ' '){
                    decide = -1;
                    i += 4;
                }
                if(decide == 0)
                    cout << (char)(65+res);
                else if (decide == -1)
                    cout << (char)(97+res) << " ";
                else
                    cout << (char)(97+res);
                i += 2;
                decide += 1;
            }
            else{
                temp[j] = str[i];
                j += 1;
            }
        }
    }
    return 0;
}