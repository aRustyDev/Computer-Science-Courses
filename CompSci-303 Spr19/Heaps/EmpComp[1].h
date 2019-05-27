
#include "Employee.h";

struct EmpComp{

public:
	bool operator ()(const Employee& emp1, const Employee& emp2){
		return emp1.name > emp2.name;
	}
};
