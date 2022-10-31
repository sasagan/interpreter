#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

class Token : public TokenType
{
private:
	TokenType type;
	string text;
	int pos;
public:
	Token(const TokenType& type, string text, int pos)
	{
		this->type = type; this->text = text; this->pos = pos;
	}
	~Token() {}
};