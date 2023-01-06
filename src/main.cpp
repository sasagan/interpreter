#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "Error.h"
#include "TokenType.h"
#include "Token.h"
#include "lexer.h"
#include "VARIABLE.h"
#include "Parser.h"

using namespace std;


int main()
{
	string code = "int a = 234;\
					LOG a;\
					int b = 2 * 6 + 4 / 2;\
					LOG b;\
					int c = a / b;\
					LOG c";

	Lexer lexer;
	lexer.lexAnalyzer(code);

	Parser parser;
	parser.syntAnalyzer(lexer.arrToken);
	//printf(lexer.arrToken[1].GetName().c_str());

	//parser.syntAnalyzer(lexer.arrToken);
	/*for (int i = 0; i < 2; i++)
	{
		cout << "name - " + parser.arrVariable[i].GetName() << endl;
		cout << "mean - " + parser.arrVariable[i].GetMean() << endl;
	}*/

	int a = 34;
	a = 12;

	return 0;
}