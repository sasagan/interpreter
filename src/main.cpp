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
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console_color, 15);
	
	while (true)
	{
		string code;//= "int a = 2;IF (a == 3 OR a <= 3) { LOG \"yes\"; }LOG a; ";

		string command;
		cout << ">>>"; getline(cin, command);

		for (int i = 0; i < command.size(); i++)
		{
			if (command[i] == '$')
			{
				if (command[i + 1] == '?')
				{
					cout << "$? Ц выводит информацию о командах интерпретатора\n$LEX Уим€ файлаФ Ц выводит токены и их типы\n$STR Уим€ файлаФ Ц запускает программу в файле" << endl;

				}
				else if (command[i + 1] == 'L' and command[i + 2] == 'E' and command[i + 3] == 'X')
				{
					string nameFile;
					for (int j = i + 5; j < command.size(); j++)
					{
						nameFile += command[j];
					}
					std::ifstream data(nameFile);
					std::string string((std::istreambuf_iterator<char>(data)), std::istreambuf_iterator<char>());
					break;
				}
				else if (command[i + 1] == 'S' and command[i + 2] == 'T' and command[i + 3] == 'R')
				{
					string nameFile;
					for (int j = i + 5; j < command.size(); j++)
					{
						nameFile += command[j];
					}
					std::ifstream data(nameFile);
					string code((std::istreambuf_iterator<char>(data)), std::istreambuf_iterator<char>());
					Lexer lexer;
					lexer.lexAnalyzer(code);

					Parser parser;
					parser.syntAnalyzer(lexer.arrToken, 0, lexer.arrToken.size());
					break;
				}
				else
				{
					SetConsoleTextAttribute(console_color, 4);
					cout << "некорректна€ команда" << endl;
					SetConsoleTextAttribute(console_color, 15);
					break;
				}
			}
			else
			{
				code = command;
				Lexer lexer;
				lexer.lexAnalyzer(code);

				Parser parser;
				parser.syntAnalyzer(lexer.arrToken, 0, lexer.arrToken.size());
				break;
			}
		}
	}
	
	//std::ifstream data("F:/Games/programming/c++/interpreter/testcode.txt");
	//std::string string((std::istreambuf_iterator<char>(data)), std::istreambuf_iterator<char>());

	//code = string;

	//ELSE { LOG \"no\"; }
	/*Lexer lexer;
	lexer.lexAnalyzer(code);

	Parser parser;
	parser.syntAnalyzer(lexer.arrToken, 0, lexer.arrToken.size());*/
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