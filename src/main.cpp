#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "TokenType.h"
#include "Token.h"
#include "lexer.h"

using namespace std;

int main()
{
	string code = "dgf j; 56 =dfr";  

	Lexer lexer;
	lexer.lexAnalyzer(code);


	return 0;
}