#include <iostream>
#include <string>
#include <fstream>
#include <regex>
using namespace std;

class TokenType
{
private:
	string name;
	string regex;
public:
	TokenType(string name, string regex)
	{
		this->name = name; this->regex = regex;
	}
	TokenType()
	{
		this->name = "";
		this->regex = "";
	}
	~TokenType() = default;
};

TokenType NUMBER("NUMBER", "[0-9]");
TokenType VARIABLE("VARIABLE", "[a-z]");
TokenType SEMICOLON("SEMICOLON", ";");
TokenType SPACE("VARIABLE", "[\t\n\r]");
TokenType ASSIGN("ASSIGN", "=");

