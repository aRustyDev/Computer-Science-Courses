
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <set>
#include <map>

using namespace std;

/** Specification file for the array-based phone directory.
*/
class Phone_Directory {

public:
	
	void load_data(const std::string& source_name);

	std::string lookup_entry(const std::string& name) const;

	std::string add_or_change_entry(const std::string& name, const std::string& number);

	std::string add_or_change_entry_2(const std::string& name, const std::string& number);

	std::string remove_entry(const std::string& name);

private:

	void add(const std::string& name, const std::string& number);
	
	std::map<string, string> the_directory;

	std::string source_name;

	bool modified;
};

void Phone_Directory::load_data(const string& source_name) {
	this->source_name = source_name;

	ifstream in(source_name.c_str());
	if (in) {
		string name;
		string number;
		while (getline(in, name)) {
			if (getline(in, number)) {
				add(name, number);
			}
		}
		// Close the file.
		in.close();
	}
}

string Phone_Directory::add_or_change_entry(const string& name, const string& number) {
	string old_number = the_directory[name];
	the_directory[name] = number;
	modified = true;
	return old_number;
}

string Phone_Directory::add_or_change_entry_2(const string& name, const string& number) {

	string old_number = "";
	pair<std::map<string, string>::iterator, bool> ret = the_directory.insert(pair<string, string>(name, number));
	if (!ret.second){
		old_number = ret.first->second;
		ret.first->second = number;
	}
	modified = true;
	return old_number;
}


string Phone_Directory::lookup_entry(const string& name) const {

map<string, string>::const_iterator itr = the_directory.find(name);
if (itr != the_directory.end())
  return itr->second;
else
  return "";
}






void Phone_Directory::add(const string& name, const string& number)
{
	the_directory[name] = number;

}

string Phone_Directory::remove_entry(const string& name) {
	string old_number = the_directory[name];
	the_directory.erase(name);
	modified = old_number != string();
	return old_number;
}


