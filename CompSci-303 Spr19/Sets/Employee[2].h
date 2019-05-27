
#include <string>
using namespace std;

class Employee{

public:
	Employee(string name, string id, string deptID) :name(name), id(id), deptID(deptID){}

	string get_deptID(){
		return deptID;
	}

private:
	string name;
	string id;
	string deptID;

};

