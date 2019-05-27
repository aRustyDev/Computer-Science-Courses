

#include "vector_Based_Phone_Directory.h"
#include "String_Tokenizer.h"
#include <fstream>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/** Function to remove the leading and trailing spaces from a string */
string trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}


/** Construct an empty Phone_Directory
*/
Phone_Directory::Phone_Directory() :
source_name("") {}

/** Destroy the Phone_Directory
*/
Phone_Directory::~Phone_Directory()
{

}

/** Function to load the data file.
pre:  The directory storage has been created and it is empty.
If the file exists, it consists lines representing each Employee.
The data fields for each Employee are separated by commas.
post: The data from the file is loaded into the directory.
@param source_name The name of the data file
*/
void Phone_Directory::load_data(const string& source_name)
{
	// Remember the source name for use by save.
	this->source_name = source_name;
	// Create an input stream for this file.
	ifstream in(source_name);
	if (in) { // Stream exists.
		string line;
		string the_name;
		string the_job_description;
		string the_phone_number;
		string the_room_number;
		while (getline(in, line)) { //read the next line in the file, if no more lines are availble, the while loop will exist.
			String_Tokenizer st(line, ","); //a tokenizer for parsing a line of tokens (the tokens are seperated by commas)
			string last_name = trim(st.next_token()); //we expect the first token in the line to be last name
			string first_name = trim(st.next_token()); //the second token is the first name
			the_name = first_name + " " + last_name;
			the_job_description = trim(st.next_token());
			the_phone_number = trim(st.next_token());
			the_room_number = trim(st.next_token());
			add_entry(Employee(the_name, the_job_description, the_phone_number,
				the_room_number));
		}
	}
	// Close the file.
	in.close();
}

/** Changes the number associated with the given name to
the new value, or adds a new entry with this name and
number.
@param new_Employee The new Employee data
*/
void Phone_Directory::change_entry(const Employee& new_Employee)
{
	int index = find(new_Employee.get_name());
	if (index != -1) {
		the_directory[index].set_job_description(new_Employee.get_job_description());
		the_directory[index].set_phone_number(new_Employee.get_phone_number());
		the_directory[index].set_room_number(new_Employee.get_room_number());
		modified = true;
	}
	else {
		add_entry(new_Employee);
	}
}

/** Look up an entry.
@param name The name of the Employee
@return a default Employee if not in the directory
*/
Employee Phone_Directory::lookup_entry(const string& name) const
{
	int index = find(name);
	if (index != -1) {
		return the_directory[index];
	}
	else {
		return Employee();
	}
}

/** Function to save the directory.
pre:  The directory has been loaded with data
post: Contents of directory written back to the file in the
form of name-number pairs on adjacent lines.
modified is reset to false.
*/
void Phone_Directory::save()
{
	if (modified) {  // if not modified, do nothing
		// Create an output stream.
		ofstream out(source_name.c_str());
		for (int i = 0; i < the_directory.size(); i++) {
			out << the_directory[i].get_name() << ", ";
			out << the_directory[i].get_job_description() << ", ";
			out << the_directory[i].get_phone_number() << ", ";
			out << the_directory[i].get_room_number() << "\n";
		}
		// Close the output stream.
		out.close();
		modified = false;
	}
}

/** Remove an entry
post: The name is no longer in the directory
@param name The name to be removed
*/
void Phone_Directory::remove_entry(const string& name)
{
	int index = find(name);
	if (index == -1)
		return;

	the_directory.erase(index);

	modified = true;
}

/** Add a new Employee to the directory.
@param the_Employee to be added
@param number The number to be added
*/
void Phone_Directory::add_entry(const Employee& the_Employee)
{

	the_directory.push_back(the_Employee);
	modified = true;
}

// Private method implementation

/** Search the array for a given name.
@param name The name to be found
@return The index of the entry containing this name
or -1 if the name is not present
*/
int Phone_Directory::find(const string& name) const
{
	for (int i = 0; i < the_directory.size(); i++) {
		if (the_directory[i].get_name() == name)
			return i;
	}
	return -1;
}


