#include <string>
#include <vector>
#include <regex>

using namespace std;

class Lexer
{
private:
	int pos = 0;

public:
	vector <Token> arrToken;
	void lexAnalyzer(string code)
	{
		//string sToken;
		const char* c_code = code.c_str();
		for (int i = 0; i < code.size(); i++)
		{
			string currentToken;
			while ((code[i] != ' ') and i < code.size())
			{
				currentToken += code[i];
				i++;
				if (code[i] == ';')
				{
					i--;
					break;
				}
				if (code[i] == '\t')
				{
					break;
				}
			}
			//string currentToken(1, c_code[i]);
			//string nextToken(1, c_code[i + 1]);

			if (regex_match(currentToken, regex(NUMBER.GetRegex())) == true)
			{
				arrToken.push_back(Token(NUMBER, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(KEYWORDS.GetRegex())) == true)
			{
				arrToken.push_back(Token(KEYWORDS, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(DATATYPE.GetRegex())) == true)
			{
				arrToken.push_back(Token(DATATYPE, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(VARIABLE.GetRegex())) == true)
			{
				arrToken.push_back(Token(VARIABLE, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(TEXT.GetRegex())) == true)
			{
				arrToken.push_back(Token(TEXT, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(SPACE.GetRegex())) == i + 1)
			{
				arrToken.push_back(Token(SPACE, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(SEMICOLON.GetRegex())) == true)
			{
				arrToken.push_back(Token(SEMICOLON, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(ASSIGN.GetRegex())) == true)
			{
				arrToken.push_back(Token(ASSIGN, currentToken, i + 1));
			}
		}
	}


};
