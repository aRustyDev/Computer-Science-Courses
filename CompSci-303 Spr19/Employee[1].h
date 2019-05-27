#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

/** Class to represent a Employee */
class Employee
{
public:
	/** Construct a new Employee
	@param the_name
	@param the_job_description
	@param the_phone_number
	@param the_room_number
	*/
	Employee(const std::string& the_name,
		const std::string& the_job_description,
		const std::string& the_phone_number,
		const std::string& the_room_number) :
		name(the_name), job_description(the_job_description),
		phone_number(the_phone_number),
		room_number(the_room_number) {}

	/** Construct a default Employee */
	Employee() : name(""), job_description(""),
		phone_number(""), room_number("") {}

	/** Get the name */
	std::string get_name() const { return name; }

	/** Get the job_description */
	std::string get_job_description() const { return job_description; }

	/** Get the phone number */
	std::string get_phone_number() const { return phone_number; }

	/** Get the room number */
	std::string get_room_number() const { return room_number; }

	/** Set the job_description */
	void set_job_description(const std::string& new_job_description) {
		job_description = new_job_description;
	}

	/** Set the running time */
	void set_phone_number(const std::string& new_phone_number) {
		phone_number = new_phone_number;
	}

	/** Set the room_number */
	void set_room_number(const std::string& new_room_number) {
		room_number = new_room_number;
	}

private:
	/** The name */
	std::string name;

	/** The job_description */
	std::string job_description;

	/** The phone number */
	std::string phone_number;

	/** The room number */
	std::string room_number;

};

#endif
