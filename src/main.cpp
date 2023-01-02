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
					int b = a;\
					string s = \"hello\";\
					LOG b;\
					LOG a;";

	Lexer lexer;
	lexer.lexAnalyzer(code);

	Parser parser;
	parser.syntAnalyzer(lexer.arrToken);
	//printf(lexer.arrToken[1].GetName().c_str());

	int a = 34;
	a = 12;

	return 0;
}