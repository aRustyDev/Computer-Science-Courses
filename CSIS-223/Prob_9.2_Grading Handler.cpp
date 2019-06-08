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
 *       GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/edit/master/CSIS-223/Prob_9.2_Grading%20Handler.cpp
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

//Structures
struct studentType
{
    string FName;
    string LName;
    int testHistory[5] = {};
    double avgScore = 0;
    double highScore = 0;
    char letterGrade = 'A';
};

//Functions
char getGrade(int percentGrade){//Takes Avg Score Returns Letter Grade
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

    //Input
    cout << endl;
    cout << "First Name: ";
    cin >> stud.FName;
    cout << "Last Name: ";
    cin >> stud.LName;
    for (int i = 0; i < 5; i++) {
        cout << "Test " << i+1 << " Score: ";
        if (cin >> stud.testHistory[i]) {//Check if (Int)
            //Check if (0 <= Int <= 100)
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
        //Get Avg Grade & Highest Score for that Student
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
        //Cycle through the group of student object.
        //Compare each students highest score and return highest scoring student
        //Does not take into account high ties.
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
    cout << left << "Name: " << stud.FName << ", " << stud.LName << endl;
    cout << left << "Grade: " << stud.letterGrade << endl;
    cout << left << "HighScore: " << stud.highScore << endl;
    cout << left << "Avg Score: " << stud.avgScore << endl;
}

int main() {
    //Variables
    int i = 20;
    int totalTests = 5;
    array<studentType, 5> studRoster = {};

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
