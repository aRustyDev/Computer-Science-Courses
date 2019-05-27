

#include "PD.h"


int main(){
	Phone_Directory phone_directory;

	phone_directory.add_or_change_entry_2("Jane Smith", "215-555-1234");
	phone_directory.add_or_change_entry_2("Jane Smith", "215-455-1234");
	phone_directory.add_or_change_entry("Bill Jones", "508-555-6123");

	string number=phone_directory.lookup_entry("Jane Smith");




	return 0;
}

