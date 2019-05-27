// doubly_linked_list_app.cpp : Defines the entry point for the console application.
//


#include "Ordered_List.h"
#include <iostream>
#include <string>

using namespace std;




void print_list(const list<string>& li){
	
	list<string>::const_iterator iter = li.begin();
	
	while (iter != li.end()){
		cout << *iter;
		++iter;
		if (iter != li.end())
			cout << " ===> ";
	}

	cout << '\n';
}

int main(){

	list<string> li;
	li.push_back("B");
	li.push_back("C");
	li.push_back("B");
	li.push_back("D");
	li.push_back("B");

	print_list(li);

	list<string>::iterator iter = li.find("C");


	list<string>::iterator iterator = li.begin();
	li.insert(iterator, "OK");
	string data = *iterator;
	data = "BBB";
	
	string* data_2 = iterator.operator->();
	*data_2 = "BB_2";

	iterator++;
	

	string b = "B";
	li.remove(b);

	//iterator example

	list<string> a_list;
	a_list.push_back("Tom");
	a_list.push_back("John");
	a_list.push_back("Harry");
	a_list.push_back("Sam");

	list<string>::iterator pos_a = a_list.find("Harry");
	
	++pos_a;
	pos_a = a_list.insert(pos_a, "Jane");
	++pos_a;
	++pos_a;
	pos_a = a_list.insert(pos_a, "Kim");
	pos_a = a_list.erase(pos_a);


	Ordered_List<int> o_list;
	o_list.insert(10);
	o_list.insert(2);
	o_list.insert(5);
	o_list.insert(1);


	return 0;
}
