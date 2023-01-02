#include <string>
#include <vector>
#include <regex>

using namespace std;

class Parser
{
private:

public:
	vector <Variable> arrVariable;
	void syntAnalyzer(vector <Token> arrToken)
	{
		for (int i = 0; i < arrToken.size(); i++)
		{
			if (arrToken[i].GetNameTokenType() == "DATATYPE")
			{
				if (arrToken[i + 1].GetNameTokenType() == "VARIABLE")
				{
					if (arrToken[i + 2].GetNameTokenType() == "SEMICOLON")
					{

					}
					else
					{
						error("error: dfgr");
					}
				}
				else
				{
					error("error: aasesss");
				}
			}
		}
	}
};
