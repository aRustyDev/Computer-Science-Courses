
#include <string>

using namespace std;

class Employee{

public:

	Employee(string name) : name(name){}

	Employee(){}

	bool operator < (const Employee other) const {
		return name < other.name;
	}

friend ostream &operator<<(ostream &out, const Employee& other){

		out << other.name;
		return out;
	}

void set_name(string name){
	this->name = name;
}



private:

	string name;

};
