
#include "vector_based_stack.h"
#include <string>

using namespace std;


class Palindrome_Finder {

public:
	Palindrome_Finder(const std::string& str) : input_string(str) {
		fill_stack();
	}

	bool is_palindrome(){
		string reverse = build_reverse();
		return equal(input_string.begin(), input_string.end(),
			reverse.begin(), Ci_Equal());
	}

private:
	/** Function to fill a stack of characters from an input string. */
	void fill_stack(){
		for (size_t i = 0; i < input_string.size(); i++) {
			char_stack.push(input_string[i]);
		}
	}


	/** Function to build a string containing the characters in a stack.
	post: The stack is empty.
	@return The string containing the words in the stack
	*/
	std::string build_reverse(){
		string result;
		while (!char_stack.empty()) {
			// Remove top item from stack and append it to result.
			result += char_stack.top();
			char_stack.pop();
		}
		return result;
	}



	std::string input_string;

	VB::stack<char> char_stack;

	/** Function class to perform case-insensitive comparison
	of characters. */
	class Ci_Equal {
	public:
		bool operator()(char c1, char c2) {
			return toupper(c1) == toupper(c2);
		}
	};

};
