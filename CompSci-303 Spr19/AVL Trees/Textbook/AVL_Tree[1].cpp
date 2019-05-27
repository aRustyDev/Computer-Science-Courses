/** Program to test a balanced search tree by comparing
it with an "ordinary" binary search tree.
*/
#include "Binary_Search_Tree.h"
#include "AVL_Tree.h"
#include "Random.h"
#include <iostream>
#include <sstream>
#include <string>
using std::ostringstream;
using std::cout;
using std::endl;
using std::string;
int main()
{
	AVL_Tree<string> avl_tre;
	avl_tre.insert("5");
	avl_tre.insert("4");
	avl_tre.insert("3");

	AVL_Tree<string> left_right_tree;
	left_right_tree.insert("6");
	left_right_tree.insert("4");
	left_right_tree.insert("5");

	AVL_Tree<string> right_left_tree;
	right_left_tree.insert("4");
	right_left_tree.insert("6");
	right_left_tree.insert("5");


	AVL_Tree<double> left_right_tree_2;
	left_right_tree_2.insert(12);
	left_right_tree_2.insert(9);
	left_right_tree_2.insert(14);
	left_right_tree_2.insert(3);
	left_right_tree_2.insert(10);
	left_right_tree_2.insert(11);

	left_right_tree_2.erase(10);
	left_right_tree_2.erase(9);
	left_right_tree_2.erase(14);


	string last_good_tree;
	int next;
	AVL_Tree<int> avl_tree;
	Random random;
	try {
		for (size_t i = 0; i < 1000; i++) {
			last_good_tree = avl_tree.to_string();
			next = random.next_int(10000);
			avl_tree.insert(next);
			avl_tree.verify_structure();
		}
	}
	catch (Bad_Structure<int>& ex) {
		cout << "Error after inserting " << next << endl;
		cout << "Bad Structure Exception " << ex.what() << endl;
		cout << ex.node->to_string() << endl;
		cout << ex.parent->to_string() << endl;
		cout << "\nLast Good Tree\n";
		cout << last_good_tree;
		cout << "\nBad Tree\n";
		cout << avl_tree.to_string() << endl;
		exit(1);
	}
	try {
		for (size_t i = 0; i < 500; i++) {
			last_good_tree = avl_tree.to_string();
			next = random.next_int(10000);
			avl_tree.erase(next);
			avl_tree.verify_structure();
		}
	}
	catch (Bad_Structure<int>& ex) {
		cout << "Error after erasing " << next << endl;
		cout << "Bad Structure Exception " << ex.what() << endl;
		cout << ex.node->to_string() << endl;
		cout << ex.parent->to_string() << endl;
		cout << "\nLast Good Tree\n";
		cout << last_good_tree;
		cout << "\nBad Tree\n";
		cout << avl_tree.to_string() << endl;
		exit(1);
	}
	cout << "Test Passed\n";
}
