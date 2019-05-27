/** Simple program to test map */

#include <iostream>
#include <string>
#include "Hash_Table_Open.h"
typedef KW::hash_map<std::string, int> map_type;

#define echo(x) #x <<": " << x

using std::string;
using std::cout;
using std::endl;

int main()
{
  // Test map insert and indexing operations

	
	KW::hash_map<string, string> hash_table(5);
	hash_table["Tom"] = "123";
	hash_table["John"] = "11";
	hash_table["Harry"] = "54";
	hash_table["Sam"] = "15";
	hash_table["Pete"] = "15";

  return 0;
}
