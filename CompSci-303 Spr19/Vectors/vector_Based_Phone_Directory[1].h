#ifndef VECTOR_BASED_PHONE_DIRECTORY_H
#define VECTOR_BASED_PHONE_DIRECTORY_H
#include <iosfwd>
#include "Employee.h"
#include "vector.h"

/** Specification file for the array-based Employee directory.
*/
class Phone_Directory
{
public:
	/** Construct an empty Employee directory.
	*/
	Phone_Directory();

	/** Destroy the Employee directory when it is no longer needed.
	*/
	~Phone_Directory();

	/** Load the data file containing the directory, or
	establish a connection with the data source.
	@param source_name The name of the file (data source)
	with the Employee directory entries.
	*/
	void load_data(const std::string& source_name);

	/** Look up an entry.
	@param name The name of the Employee to look up
	@return Employee
	*/
	Employee lookup_entry(const std::string& name) const;

	/** Inserts a new Employee into the directory.
	@param new_Employee The new Employee.
	*/
	void add_entry(const Employee& new_Employee);

	/** Changes the data associated with a given Employee.
	@param new_Employee The new Employee.
	*/
	void change_entry(const Employee& new_Employee);

	/** Removes the entry with the specified Employee from the directory.
	@param name The name of the Employee to be removed
	*/
	void remove_entry(const std::string& name);

	/** Writes the contents of the directory to the data file.
	*/
	void save();


private:
	// Private Functions
	/** Searches the array of directory entries for the name.
	@param name The name to be found
	@return The index of the entry containing the name, or -1
	if the name is not found
	*/
	int find(const std::string& name) const;



	/** Pointer to the vector containing the directory data. */
	KW::vector<Employee> the_directory;
	/** The name of the data file that contains the directory data. */
	std::string source_name;
	/** Boolean flag to indicate whether the directory was
	modified since it was either loaded or saved. */
	bool modified;
};

#endif
