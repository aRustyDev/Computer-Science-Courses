

#include "AVL_Tree.h"
#include "Employee.h"

using namespace std;

int main(){

	AVL_Tree<string> AVL;

	bool result = AVL.is_null();

	Employee* empl=new Employee("X");
	Employee* emp2=new Employee("Y");

	AVL_Tree<Employee*> AVL_Employees;

	AVL_Employees.insert(empl);

	AVL_Employees.insert(emp2);

	Employee* emp = AVL_Employees.find(empl);

	emp->set_name("Z");

	//AVL.insert(50);
	//AVL.insert(60);
	//AVL.insert(70);


	AVL.insert("The");
	AVL.insert("quick");

	

	AVL.insert("brown");
	AVL.insert("fox");
	AVL.insert("jumps");
	AVL.insert("over");
	AVL.insert("the");
	AVL.insert("lazy");
	AVL.insert("dog");

	AVL.erase("jumps");

	AVL_Tree<string> right_subtree = AVL.get_right_subtree();

	AVL_Tree<string> left_subtree = AVL.get_left_subtree();


	return 0;
}
