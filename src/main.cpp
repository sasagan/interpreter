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
	setlocale(LC_ALL, "Russian");


	string code = "int a = 2;\
					IF (a == 3 OR a <= 3 AND a == 4) { \
					LOG \"yes\"; }\
					LOG a; ";
	//ELSE { LOG \"no\"; }
	Lexer lexer;
	lexer.lexAnalyzer(code);

	Parser parser;
	parser.syntAnalyzer(lexer.arrToken, 0, lexer.arrToken.size());
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