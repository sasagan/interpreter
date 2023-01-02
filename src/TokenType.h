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
	string GetName()
	{
		return name;
	}
	string GetRegex()
	{
		return regex;
	}

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

TokenType NUMBER("NUMBER", "[0-9]+");
TokenType TEXT("TEXT", "\".+\"");
TokenType SEMICOLON("SEMICOLON", ";");
TokenType LEFTPARENTHESIS("LEFTPARENTHESIS", "(");
TokenType RIGHTPARENTHESIS("RIGHTPARENTHESIS", ")");
TokenType SPACE("SPACE", "[\t\n\r]");
TokenType ASSIGN("ASSIGN", "=");

TokenType KEYWORDS("KEYWORDS", "LOG|IF|FOR");
TokenType DATATYPE("DATATYPE", "int|string|boolean|float");
TokenType VARIABLE("VARIABLE", "[a-zA-Z_]+[0-9]+[a-zA-Z_]+|[a-zA-Z_]+[0-9]+|[a-zA-Z_]+");
