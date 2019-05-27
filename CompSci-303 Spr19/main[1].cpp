#include <iostream>
using namespace std;

int main(){

	/*pointers + references: reference: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html */

	int number1 = 88, number2 = 22;

	// Create a pointer pointing to number1
	int * pNumber1 = &number1;  // Explicit referencing
	*pNumber1 = 99;             // Explicit dereferencing
	cout << *pNumber1 << endl;  // 99
	cout << &number1 << endl;   // 0x22ff18
	cout << pNumber1 << endl;   // 0x22ff18 (content of the pointer variable - same as above)
	cout << &pNumber1 << endl;  // 0x22ff10 (address of the pointer variable)
	pNumber1 = &number2;        // Pointer can be reassigned to store another address

	// Create a reference (alias) to number1
	int & refNumber1 = number1;  // Implicit referencing (NOT &number1)
	refNumber1 = 11;             // Implicit dereferencing (NOT *refNumber1)
	cout << refNumber1 << endl;  // 11
	cout << &number1 << endl;    // 0x22ff18
	cout << &refNumber1 << endl; // 0x22ff18
	//refNumber1 = &number2;     // Error! Reference cannot be re-assigned
	// error: invalid conversion from 'int*' to 'int'
	refNumber1 = number2;        // refNumber1 is still an alias to number1.
	// Assign value of number2 (22) to refNumber1 (and number1).
	number2++;
	cout << refNumber1 << endl;  // 22
	cout << number1 << endl;     // 22
	cout << number2 << endl;     // 23

	return 0;
}
