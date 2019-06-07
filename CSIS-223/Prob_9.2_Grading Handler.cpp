/*      Title: Force UPPERCASE | Problem 9.
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
 *      Purpose: Read from Names and test scores from Input, return Highest test,
 *               and average test score i.e. Grades
 *
 * */
/*      Notes:
 *
 *
*/

#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

struct studentType
{
    string FName;
    string LName;
    int testHistory[5] = {};
    double avgScore = 0;
    double highScore = 0;
    char letterGrade = 'A';
};

char getGrade(int percentGrade){
    switch(percentGrade){
        case 90 ... 100 : return 'A';
        case 80 ... 89 : return 'B';
        case 70 ... 79 : return 'C';
        case 60 ... 69 : return 'D';
        case 0 ... 59 : return 'F';
    }
}
studentType getStudent(int totalTests) {
    //Local Var
    studentType stud;
    double cumulatePts = 0;
    double highestTest = 0;
    double testScore;

    //Input
    cout << endl;
    cout << "First Name: ";
    cin >> stud.FName;
    cout << "Last Name: ";
    cin >> stud.LName;
    for (int i = 0; i < 5; i++) {
        cout << "Test " << i+1 << " Score: ";
        if (cin >> stud.testHistory[i]) {
            if (stud.testHistory[i] <= 100 && stud.testHistory[i] >= 0){
                continue;
            }else{
                i--;
                cout << "Please enter a value between 0-100" << endl;
            }
        } else {
            i--;
            cout << "Please enter a value between 0-100" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    //Processing
    for (int i = 0; i < totalTests; i++) {
        cumulatePts += stud.testHistory[i];
        if (stud.testHistory[i] > highestTest) {
            highestTest = stud.testHistory[i];
        }
    }
    stud.avgScore = (cumulatePts / totalTests);
    stud.highScore = highestTest;
    stud.letterGrade = getGrade(stud.avgScore);

    return stud;
}
void getHighestScore(array<studentType,5> studRoster){
    int classSize = studRoster.size();
    studentType highestScorer;
    studentType stud;
    double highestTest = 0;

    for(int i = 0; i < classSize; i++){
        stud = studRoster[i];
        if(stud.highScore > highestTest){
            highestTest = stud.highScore;
            highestScorer = stud;
        }
    }
    cout << endl << "Highest Scorer: "
        << highestScorer.FName << " " << highestScorer.LName << endl;
    cout << highestScorer.highScore << endl;
}
void outputRoster(studentType stud){
    cout << endl;
    cout << "Name: " << stud.FName << " " << stud.LName << endl;
    cout << "Grade: " << stud.letterGrade << endl;
    cout << "HighScore: " << stud.highScore << endl;
    cout << "Avg Score: " << stud.avgScore << endl;
}

int main() {
    //Variables
    array<studentType, 5> studRoster = {};
    int i = 3;
    int totalTests = 5;

    //Input
    cout << "Class Size: " << i << endl;

    //Function Calls
    for (int k = 0; k < i; k++) {
        studRoster[k] = getStudent(totalTests);
    }

    for (int k = 0; k < i; k++) {
        outputRoster(studRoster[k]);
    }
    getHighestScore(studRoster);

    return 0;
}
