
#include "map.h"
#include "Employee.h"
#include "Department.h"

class Database{

public:

	void add_employee(string id, string name, string deptID){
		employee_table.insert[id] = Employee(id, name, deptID);
	}

	void add_department(string id, string name){
		department_table[id] = Department(id, name);
	}

	void print_department(string employee_id){
		Employee emp = employee_table[employee_id];
		Department dept = department_table[emp.get_deptID()];
	}


private:
	KW::Map<string, Employee> employee_table;
	KW::Map<string, Department> department_table;

};
