// stack_app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

#include "Palindrome_Finder.h"
#include "linked_list_stack.h"


using namespace std;

// The set of opening parentheses.
const string OPEN = "([{";
// The corresponding set of closing parentheses.
const string CLOSE = ")]}";

bool is_open(char ch) {
	return OPEN.find(ch) != string::npos;
}

bool is_close(char ch) {
	return CLOSE.find(ch) != string::npos;
}

bool is_balanced(const string& expression) {
	// A stack for the open parentheses that haven't been matched
	VB::stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end())) {
		char next_ch = *iter;
		if (is_open(next_ch)) {
			s.push(next_ch);
		}
		else if (is_close(next_ch)) {
			if (s.empty()) {
				balanced = false;
			}
			else {
				char top_ch = s.top();
				s.pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		++iter;
	}
	return balanced && s.empty();
}



string convert_decimal_binary(int decimal){
	//assuming the decimal is positive

	VB::stack<int> stack;
	int result = 0, i = 0;
	while (decimal != 0){
		stack.push(decimal % 2);
		decimal /= 2;
	}

	std::ostringstream ostr; // a stream to convert an integer to string
	ostr.str("");
	while (!stack.empty()){
		ostr << stack.top();
		stack.pop();
	}

	return ostr.str();
}


int main()
{
	VB::stack<string> names;

	names.push("Rich");
	names.push("Debbie");
	names.push("Robin");
	names.push("Dustin");
	names.push("Jonathan");

	string last = names.top();

	names.pop();

	names.push("Philip");

	SLL::stack<string> stack_2;
	stack_2.push("A");
	stack_2.push("B"); 
	stack_2.push("C");

	string top = stack_2.top();
	

	//testing if an expression is a palindrome
	Palindrome_Finder pal("kayak");

	bool result=pal.is_palindrome();

	//convert a decimal number into a binary number
	string str = convert_decimal_binary(5);

	//check if the expression is balanced
	bool result_1 = is_balanced("a{b[c]d}e");
	bool result_2 = is_balanced("A{b(c]d}e");

	return 0;
}

