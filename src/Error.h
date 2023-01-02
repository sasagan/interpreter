#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void error(string text)
{
	cout << text << endl;
	abort();
}
