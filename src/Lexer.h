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


			/*if (code[i] == ';' or code[i] == '(' or code[i] == ')' or code[i] == '{' or code[i] == '}')
			{
				currentToken = code[i];
			}
			else if (code[i] == '=' and code[i+1] == '=')
			{
				currentToken = code[i] + code[i + 1];
			}
			else if (code[i] == '\t')
			{
				continue;
			}
			else
			{
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
			}*/

			if (code[i] == ';' or code[i] == '(' or code[i] == ')' or code[i] == '{' or code[i] == '}')
			{
				currentToken = code[i];
			}
			else if (code[i] == '\t' or code[i] == '\n')
			{
				continue;
			}
			else 
			{
				while ((code[i] != ' ') and i < code.size())
				{
					if (code[i] == '\"')
					{
						currentToken += code[i];
						i++;
						while (code[i] != '\"')
						{
							currentToken += code[i];
							i++;

						}
						currentToken += code[i];
						i++;
						if (code[i] == ';' or (code[i] == '=' and code[i + 1] == '=') or code[i] == '(' or code[i] == ')' or code[i] == '{' or code[i] == '}')
						{
							i--;
							break;
						}
						if (code[i] == '\t' or code[i] == '\n')
						{
							break;
						}
					}
					else
					{
						currentToken += code[i];
						i++;

						if (code[i] == ';' or (code[i] == '=' and code[i + 1] == '=') or code[i] == '(' or code[i] == ')' or code[i] == '{' or code[i] == '}')
						{
							i--;
							break;
						}
						if (code[i] == '\t')
						{
							break;
						}
					}
				}
			}



			/*while ((code[i] != ' ') and i < code.size())
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
			}*/


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
				string b = currentToken.erase(0, 1);
				b = currentToken.erase(currentToken.size() - 1, 1);
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
			else if (regex_match(currentToken, regex(COMPARISON.GetRegex())) == true)
			{
				arrToken.push_back(Token(COMPARISON, currentToken, i + 1));
			}
			else if (regex_match(currentToken, regex(ASSIGN.GetRegex())) == true)
			{
				arrToken.push_back(Token(ASSIGN, currentToken, i + 1));
			}
			else if (currentToken == "+" || currentToken == "-" || currentToken == "*" || currentToken == "/")
			{
				arrToken.push_back(Token(ARITHMETICOPERATIONS, currentToken, i + 1));
			}
			else if (currentToken == "(")
			{
				arrToken.push_back(Token(LEFTPARENTHESIS, currentToken, i + 1));
			}
			else if (currentToken == ")")
			{
				arrToken.push_back(Token(RIGHTPARENTHESIS, currentToken, i + 1));
			}
			else if (currentToken == "{")
			{
				arrToken.push_back(Token(LEFTCURLYBRACES, currentToken, i + 1));
			}
			else if (currentToken == "}")
			{
				arrToken.push_back(Token(RIGHTCURLYBRACES, currentToken, i + 1));
			}
		}
	}


};
