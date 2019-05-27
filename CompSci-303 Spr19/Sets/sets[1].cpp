// sets.cpp : Defines the entry point for the console application.
//


#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace  std;
#include "Set_Functions.h"
#include "map.h"

using namespace KW;

int count_occurences(const multiset<string>& words_set, const string& target) {
		multiset<string>::const_iterator first_itr = words_set.lower_bound(target);
		cout << "*first_itr == " << (first_itr != words_set.end() ? *first_itr : "end()") << endl;
		multiset<string>::const_iterator last_itr = words_set.upper_bound(target);
		cout << "*last_itr == " << (last_itr != words_set.end() ? *last_itr : "end()") << endl;
		int count = 0;
		for (multiset<string>::const_iterator itr = first_itr; itr != last_itr; ++itr)
			++count;
		return count;
}


int main()
{
	set<string> set1;
	set<string> set2;
	set<string> set_u;
	set<string> set_d;
	set<string> set_i;
	

	multiset<string> m_set1;
	multiset<string> m_set2;

	string data1 [] = { "Apples", "Oranges", "Tomatoes", "Pineapples","Apples","Apples" };
	string data2 [] = { "Peaches", "Apples", "Grapes" };
	string data3 [] = { "Figs", "Figs", "Apples", "Oranges" };

	m_set1.insert(data3, data3 + 4);
	int count = count_occurences(m_set1, "Figs");

	//m_set1.lower_bound("Oranges")

	set1.insert(data1, data1 + 6);

	set2.insert(data2, data2 + 3);
	cout << "set1 is " << set1 << endl;
	cout << "set2 is " << set2 << endl;

	set_u= set1 + set2;

	cout << "set1 + set2 is " << set_u << endl;

	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set_u, set_u.begin()));

	cout << "set1 + set2 is " << set_u << endl;

	set_d = set1 - set2;
	cout << "set1 - set2 is " << set_d << endl;

	set_difference(set1.begin(), set1.end(),
		set2.begin(), set2.end(),
		inserter(set_d, set_d.begin()));
	cout << "set1 - set2 is " << set_d << endl;

	set_i = set1*set2;

	set_intersection(set1.begin(), set1.end(),
		set2.begin(), set2.end(),
		inserter(set_i, set_i.begin()));
	cout << "set1 * set2 is " << set_i << endl;

	bool is_member = (set1.find(string("Apples")) != set1.end());
	cout << "\"Apples\" is an element of set1 is "
		<< boolalpha << is_member << endl;


	//testing maps

	
	Map<string, string> a_map;
	a_map["J"] = "Jane";
	a_map["J"] = "Job";
	a_map["B"] = "Bill";
	a_map["S"] = "Sam";
	a_map["B1"] = "Bob";
	a_map["B2"] = "Bill";

	Map<string,string>::iterator it=a_map.find("J");

	return 0;
}

