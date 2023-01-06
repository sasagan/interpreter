#include <string>
#include <vector>
#include <regex>

using namespace std;

class Parser
{
private:
	int priority(string operation)
	{
		if (operation == "+" or operation == "-")
		{
			return 1;
		}
		else if (operation == "*" or operation == "/")
		{
			return 2;
		}
	}
public:
	vector <Variable> arrVariable;

	int mathExpressionAnalyzerInt(vector <Token> arrToken, int start, int end)
	{
		vector <int> arrNum;
		vector <string> arrOperations;

		for (int i = start; i < end; i++)
		{
			if (arrToken[i].GetNameTokenType() == "NUMBER")
			{
				arrNum.push_back(stoi(arrToken[i].GetTextToken()));
			}
			else if (arrToken[i].GetNameTokenType() == "ARITHMETICOPERATIONS")
			{
				if (arrNum.size() < 2)
				{
					arrOperations.push_back(arrToken[i].GetTextToken());
				}
				else if (arrNum.size() >= 2)
				{
					arrOperations.push_back(arrToken[i].GetTextToken());
					if (priority(arrOperations[arrOperations.size() - 1]) <= priority(arrOperations[arrOperations.size() - 2]))
					{
						if (arrOperations[arrOperations.size() - 2] == "+")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] + arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 2] == "-")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] - arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 2] == "*")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] * arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 2] == "/")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] / arrNum[arrNum.size() - 1];
						}
						arrNum.pop_back();
						arrOperations[arrOperations.size() - 2] = arrOperations[arrOperations.size() - 1];
						arrOperations.pop_back();

					}
				}
				
			}
			else if (arrToken[i].GetNameTokenType() == "VARIABLE")
			{
				for (int j = 0; j < arrVariable.size(); j++)
				{
					if (arrVariable[j].GetName() == arrToken[i].GetTextToken())
					{
						arrNum.push_back(stoi(arrVariable[j].GetMean()));
						break;
					}
					if (j == arrVariable.size() - 1 and arrVariable[j].GetName() != arrToken[i].GetTextToken())
					{
						error("asfdse");
					}
				}
			}
			else
			{
				error("error: что то там");
			}
			if (i == end-1)
			{
				if (arrToken[i].GetNameTokenType() == "NUMBER" or arrToken[i].GetNameTokenType() == "VARIABLE")
				{
					//arrNum.push_back(stoi(arrToken[i].GetTextToken()));
					if (arrOperations.size() >= 1)
					{
						for (int j = arrOperations.size()-1; j >= 0; j--)
						{
							if (arrOperations[j] == "+")
							{
								arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] + arrNum[arrNum.size() - 1];
							}
							else if (arrOperations[j] == "-")
							{
								arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] - arrNum[arrNum.size() - 1];
							}
							else if (arrOperations[j] == "*")
							{
								arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] * arrNum[arrNum.size() - 1];
							}
							else if (arrOperations[j] == "/")
							{
								arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] / arrNum[arrNum.size() - 1];
							}
							arrNum.pop_back();
							//arrOperations.pop_back();
						}
					}
				}
				/*if (arrToken[i].GetNameTokenType() == "NUMBER" or arrToken[i].GetNameTokenType() == "VARIABLE")
				{
					//arrNum.push_back(stoi(arrToken[i].GetTextToken()));
					if (arrOperations.size() >= 1)
					{
						if (arrOperations[arrOperations.size() - 1] == "+")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] + arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 1] == "-")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] - arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 1] == "*")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] * arrNum[arrNum.size() - 1];
						}
						else if (arrOperations[arrOperations.size() - 1] == "/")
						{
							arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 2] / arrNum[arrNum.size() - 1];
						}
						arrNum.pop_back();
						arrOperations.pop_back();
					}
					
				}*/
				
			}
			
		}
		return arrNum[0];
	}


	void syntAnalyzer(vector <Token> arrToken)
	{
		for (int i = 0; i < arrToken.size(); i++)
		{
			if (arrToken[i].GetNameTokenType() == "DATATYPE")
			{
				if (arrToken[i + 1].GetNameTokenType() == "VARIABLE")
				{
					if (arrToken[i + 2].GetNameTokenType() == "ASSIGN")
					{
						int j = i+3;
						while (arrToken[j].GetNameTokenType() != "SEMICOLON")
						{
							j++;
						}
						arrVariable.push_back(Variable(arrToken[i + 1].GetTextToken(), to_string(mathExpressionAnalyzerInt(arrToken, i+3, j)), arrToken[i].GetTextToken()));
						//funcmath
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
			else if (arrToken[i].GetNameTokenType() == "KEYWORDS")
			{
				if (arrToken[i].GetTextToken() == "LOG")
				{
					if (arrToken[i + 1].GetNameTokenType() == "VARIABLE")
					{
						for (int j = 0; j < arrVariable.size(); j++)
						{
							if (arrToken[i + 1].GetTextToken() == arrVariable[j].GetName())
							{
								cout << arrVariable[j].GetMean() << endl;
								break;

							}
						}
					}
				}
			}
		}
	}
};
