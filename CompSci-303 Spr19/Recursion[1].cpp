
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

int binary_search(const std::vector<int>& items,int first, int last, int target) {

	if (first > last)
		return -1;     // Base case for unsuccessful search.
	else {
		int middle = (first + last) / 2;  // Next probe index.

		if (target < items[middle])
			return binary_search(items, first, middle - 1, target);
		else if (items[middle] < target)
			return binary_search(items, middle + 1, last, target);
		else
			return middle;   // Base case for successful search.
	}

}

int binary_search(const std::vector<int>& items, int target){

	return binary_search(items, 0, items.size() - 1, target);

}


int triangle(int n){
	if (n == 1)
	return 1;

	return (n + triangle(n - 1));
}


int average(list<int>& li, list<int>::iterator itr, int total){

	if (itr == li.end())
		return total/li.size();

	total += *itr;
	
	return average(li, ++itr, total);
}

int avg(list<int>& li){
	
	if (li.empty())
		throw std::exception("list is empty");
	
	return average(li, li.begin(), 0);
}


int linear_search(vector<int>& items, int& target, size_t pos_first) {

	if (pos_first == items.size())
		return -1;
	if (target == items[pos_first])
		return pos_first;
	else
		return linear_search(items, target, pos_first + 1);
}

int linear_search(vector<int>& items, int& target){
	return linear_search(items, target, 0);
}


int fibonacci(int n) {

	if (n <= 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}




int fib_recursive(int fib_n_1, int fib_n_2, int n){
	if (n <= 2)
		return fib_n_1;
	return fib_recursive(fib_n_1 + fib_n_2, fib_n_1, n-1);
}

int fib_wrapper(int n){
	if (n <= 2)
		return 1;
	else
		return fib_recursive(1, 1, n);
}



int fibo(int curr, int prev, int n) {
	if (n <= 1)
		return curr;
	else
		return fibo(curr + prev, curr, n - 1);
}

int fibonacci_start(int n) {
	return fibo(1, 0, n);
}




int fibonacci(int n, int& num_passes) {
	num_passes++;

	if (n <= 2)
		return 1;
	else
		return fibonacci(n - 1,num_passes) + fibonacci(n - 2,num_passes);
}

long long fib_iterative(int n){
	if (n <= 2)
		return 1;
	long long fib_n_2 = 1; //fib_1
	long long fib_n_1 = 1; //fib_2
	long long fib_n = 0;
	while (n > 2){
		fib_n = fib_n_1 + fib_n_2;

		/*next fibs*/
		fib_n_2 = fib_n_1;
		fib_n_1 = fib_n;
		--n; //decrease n
	}
	return fib_n;
}

int fibo_direct(int n){

	return (1 / sqrt(5))*(pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n));

}


void Anagram(string original, string text, size_t size, int pos, int& i) {
	if (size>2 && pos == 1) //look at a smaller string
		Anagram(text, text, size - 1, 1, i);

	if (pos >= 1){
		text = original;
		swap(text[original.size() - size], text[original.size() - size + pos]);
		cout << ++i << text << endl;
	}

	if (size>2) //look at a smaller string
		Anagram(text, text, size - 1, 1, i);

	if (pos + 1<size) //change the position of the char you want to swap
		Anagram(original, text, size, pos + 1, i);
}

void Anagraming(string text){ //wrapper function
	int i = 1;
	cout << i << text << endl;
	if (text.size() <= 1)
		return;
	Anagram(text, text, text.size(), 1, i);
}







int main()
{

	int res_1 = triangle(5);

	int res_5 = fibonacci(5); 


	long long fib_5 = fib_iterative(50);
	

	int new_fib = fib_wrapper(50);

	int num_passes = 0;
	int i = 0;
	
	Anagraming("abcd");


	num_passes = 0;

	int fib = fibonacci(5,num_passes);

	int fib_2 = fibo_direct(5);

	vector<int> v1;

	for (int i = 0; i < 9; i++)
		v1.push_back(i);
	int pos = 4;

	int result = linear_search(v1, pos);

	list<int> li;
	li.push_back(1);
	li.push_back(5);
	li.push_back(3);

	int avg_result = avg(li);

	std::vector<int> vec{ 3, 12, 21, 33, 44, 64, 70, 88, 90 };

	int search_result = binary_search(vec, 33);



	return 0;
}

