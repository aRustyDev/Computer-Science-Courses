/** Employee phone directory application that uses console I/O. */

#include "User_Interface.h"


void print_vector(const KW::vector<string>& v){
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl; //this will call the const overloading of []
}


int main()
{
	std::vector<string> vector1{ "0", "1", "2", "3" };
	//string a = vector1.at(5);


	

	KW::vector<string> my_vector;


	std::ostringstream ostr; // a stream to convert an integer to string
	
	for (int i = 0; i < 11; i++) {
		ostr.str(""); //reset the string stream
		ostr << i;
		my_vector.push_back(ostr.str()); // at index 10, the vector will reallocate double the space
	}

	print_vector(my_vector);
	string b = "b";

	string& a = my_vector[2];
	a = "new value";
	string c = my_vector[2];
	

	my_vector.putBack(2);

	KW::vector<string> vector_2;
	vector_2 = my_vector;

	

	//it = my_vector.begin();

	//my_vector.insert(it+2, "Doc");

	//my_vector.insert(2, "Doc");
	//my_vector.push_back("Dopey");

	string dwarf = my_vector[2];
	my_vector[2] = "Sneezy";



	Phone_Directory the_directory;
	the_directory.load_data("phone.dat");
	User_Interface userinterface(the_directory);
	userinterface.process_commands();
}



