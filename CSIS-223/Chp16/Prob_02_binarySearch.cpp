/*      Title: binarySearch.cpp | Problem 16.02
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
 *      GitHub: https://github.com/RedGrinGrumbler/Computer-Science-Courses/blob/master/CSIS-223/Chp16
 *
 *      Purpose: Build a Random Arr of size 10, sort it w/ bubblesort, and search it using a binary search.
 *
 */
#include <iostream>
#include <random>

using namespace std;

void printArray(int arr[], int size);
void bubbleSort(int arr[], int n);

void swap(int *a, int *b, int space){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    for(int i = 0; i < space; i++){
        cout << "   ";
    }
    cout << *b << "->" << *a << endl;
}

void bubbleSort(int arr[], int n){
    int i, j;

    for (i = 0; i < n - 1; i++) {
        cout << "\n- - - - - - -\nPass " << i + 1 << endl;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                printArray(arr, n);
                swap(&arr[j], &arr[j + 1], j);
            }
        }
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int binarySearch(int arr[], int left, int right, int x)
{//Recursively search left & right sub arrays for x
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {//Look in middle of Arr
            return mid;
        }
        if (arr[mid] > x) {//If middle of Arr is bigger than X, search left sub array
            return binarySearch(arr, left, mid - 1, x);
        }//else if middle of Arr is smaller than X, search right sub array
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element is not in array
    return -1;
}

int main(){
    //Variables
    int x;
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }//Build a Random Arr
    int n = sizeof(arr)/sizeof(arr[0]);

    //Call Bubblesort Algorithm
    bubbleSort(arr, n);

        //Print out Results
        cout << "\n- - - - - - - - - - - - \n ";
        cout<<"\t::Sorted array::";
        cout << "\n- - - - - - - - - - - - \n ";
        printArray(arr, n);

    cout << "Number to Search for: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d, Position %d",
                            result, result+1);

    return 0;
}  
