#include <string>
#include <vector>
#include <regex>

using namespace std;

class Lexer
{
private:
	int pos = 0;
	vector <Token> arrToken;
public:

	void lexAnalyzer(string code)
	{
		string sToken;
		const char* c_code = code.c_str();
		for (int i = 0; i < code.size() ; i++)
		{
			string currentToken(1, c_code[i]);
			string nextToken(1, c_code[i + 1]);
			if (regex_match(currentToken, regex("[0-9]")) == true)
			{
				sToken += currentToken;
				if (regex_match(nextToken, regex("[0-9]")) == false)
				{
					arrToken.push_back(Token(NUMBER, sToken, pos));
					sToken = "";
				}
			}
			else if (regex_match(currentToken, regex("[a-z]")) == true)
			{
				sToken += currentToken;
				if (regex_match(nextToken, regex("[a-z]")) == false)
				{
					arrToken.push_back(Token(VARIABLE, sToken, pos));
					sToken = "";
				}
			}
			else if (regex_match(currentToken, regex("[\t\n\r]")) == true)
			{
				sToken += currentToken;
				if (regex_match(nextToken, regex("[\t\n\r]")) == false)
				{
					arrToken.push_back(Token(SPACE, sToken, pos));
					sToken = "";
				}
			}
			else if (code[i] == ';')
			{
				arrToken.push_back(Token(SEMICOLON, currentToken, pos));
			}
			else if (code[i] == '=')
			{
				arrToken.push_back(Token(ASSIGN, currentToken, pos));
			}
		}


		
	}

};