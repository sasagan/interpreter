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
	string GetTextToken()
	{
		return text;
	}
	string GetNameTokenType()
	{
		return type.GetName();
	}
	string GetRegexTokenType()
	{
		return type.GetRegex();
	}

	Token(const TokenType& type, string text, int pos)
	{
		this->type = type; this->text = text; this->pos = pos;
	}
	~Token() {}


};
