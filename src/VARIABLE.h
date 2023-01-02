#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Variable
{
private:
	string datatype;
	string name;
	string mean;
public:
	Variable(string name, string mean, string datatype)
	{
		this->name = name; this->mean = mean; this->datatype = datatype;
	}
	~Variable() {}
};
