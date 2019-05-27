#include "vector_Based_Phone_Directory.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class User_Interface{
private:
	Phone_Directory the_directory;

public:
	User_Interface(Phone_Directory& the_directory) :the_directory(the_directory){}
	void process_commands()
	{
		string commands[] = { //the options the user is given
			"Add Entry",
			"Change Entry",
			"Look Up Entry",
			"Remove Entry",
			"List by Job_Description",
			"Sort by Room_Number",
			"Sort by Name",
			"Save Directory",
			"Exit" };
		const size_t NUM_COMMANDS = 9;
		size_t choice = NUM_COMMANDS - 1;
		do {
			for (size_t i = 0; i < NUM_COMMANDS; i++) {
				cout << "Select: " << i << " " << commands[i] << "\n";
			}
			cin >> choice;
			cin.ignore(numeric_limits<int>::max(), '\n');
			switch (choice) {
			case 0: do_add_entry(); break;
			case 1: do_change_entry(); break;
			case 2: do_lookup_entry(); break;
			case 3: do_remove_entry(); break;
			case 4: do_save(); break;
			case 5: do_save(); break;
			}
		} while (choice < NUM_COMMANDS - 1);
	}

	void do_add_entry()
	{
		string name;
		string job_description;
		string phone_number;
		string room_number;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter job description: ";
		getline(cin, job_description);
		cout << "Enter phone number: ";
		getline(cin, phone_number);
		cout << "Enter room number: ";
		getline(cin, room_number);
		the_directory.add_entry(Employee(name, job_description, phone_number, room_number));
		cout << name << " has been added\n";
	}

	void change_name(Employee& employee) {
		Employee old_employee = employee;
		string new_name;
		cout << "Enter new name: ";
		cin.ignore(numeric_limits<int>::max(), '\n'); //ignore new lines
		getline(cin, new_name);
		employee = Employee(new_name, old_employee.get_job_description(),
			old_employee.get_phone_number(),
			old_employee.get_room_number());
	}

	void change_job_description(Employee& employee) {
		string new_job_description;
		cout << "Enter new job_description: ";
		cin.ignore(numeric_limits<int>::max(), '\n');
		getline(cin, new_job_description);
		employee.set_job_description(new_job_description);
	}

	void change_phone_number(Employee& employee) {
		string new_phone_number;
		cout << "Enter new running time: ";
		cin.ignore(numeric_limits<int>::max(), '\n');
		getline(cin, new_phone_number);
		employee.set_phone_number(new_phone_number);
	}

	void change_room_number(Employee& employee) {
		string new_room_number;
		cout << "Enter new room_number of release: ";
		cin.ignore(numeric_limits<int>::max(), '\n');
		getline(cin, new_room_number);
		employee.set_room_number(new_room_number);
	}

	void do_change_entry()
	{
		string name;
		cout << "Enter the name: ";
		getline(cin, name);
		Employee employee = the_directory.lookup_entry(name);
		if (employee.get_name() == "") {
			cout << name << " is not in the directory\n";
			return;
		}
		int choice = 0;
		while (choice < 5) {
			cout << "Select field to change \n"; //options for changing an entry
			cout << "1. Name:         " << employee.get_name() << endl;
			cout << "2. Job_Description:      " << employee.get_job_description() << endl;
			cout << "3. Running time:  " << employee.get_phone_number() << endl;
			cout << "4. Room_Number: " << employee.get_room_number() << endl;
			cout << "5. Committ changes\n";
			cout << "6. Abandon changes\n";
			cin >> choice;
			switch (choice) {
			case 1: change_name(employee); break;
			case 2: change_job_description(employee); break;
			case 3: change_phone_number(employee); break;
			case 4: change_room_number(employee); break;
			case 5: break;
			case 6: break;
			default: cout << "Invalid choice\n";
				choice = 0;
				break;
			}
		}
		if (choice != 5) return;
		if (employee.get_name() != name) { //The name changed
			the_directory.remove_entry(name);
			the_directory.add_entry(employee);
		}
		else {
			the_directory.change_entry(employee);
		}
	}


	void do_lookup_entry()
	{
		string name;
		cout << "Enter name: ";
		getline(cin, name);
		Employee employee = the_directory.lookup_entry(name);
		if (employee.get_name() == "") {
			cout << name << " is not in the directory\n";
		}
		else {
			cout << "Name:         " << employee.get_name() << endl;
			cout << "Job_Description:      " << employee.get_job_description() << endl;
			cout << "Running time:  " << employee.get_phone_number() << endl;
			cout << "Room Number: " << employee.get_room_number() << endl;
		}
	}

	void do_remove_entry()
	{
		string name;
		cout << "Enter name: ";
		getline(cin, name);
		the_directory.remove_entry(name);
		cout << name << " has been removed from the directory\n";
	}

	void do_save()
	{
		the_directory.save();
	}
};