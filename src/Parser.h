#include <string>
#include <vector>
#include <regex>

using namespace std;

class Parser
{
private:
	int priority(string operation)
	{
		if (operation == "OR")
		{
			return 0;
		}
		else if (operation == "AND")
		{
			return 1;
		}
		else if (operation == ">" or operation == ">=" or operation == "==" or operation == "<=" or operation == "<")
		{
			return 2;
		}
		else if (operation == "+" or operation == "-")
		{
			return 3;
		}
		else if (operation == "*" or operation == "/")
		{
			return 4;
		}
	}
public:
	vector <Variable> arrVariable;


	string ExpressionAnalyzerString(vector <Token> arrToken, int start, int end)
	{
		vector <string> arrWords;
		vector <string> arrOperations;

		for (int i = start; i < end; i++)
		{
			if (arrToken[i].GetNameTokenType() == "TEXT")
			{
				arrWords.push_back(arrToken[i].GetTextToken());
			}
			else if (arrToken[i].GetNameTokenType() == "ARITHMETICOPERATIONS")
			{
				if (arrWords.size() < 2)
				{
					arrOperations.push_back(arrToken[i].GetTextToken());
				}
				else if (arrWords.size() >= 2)
				{
					arrOperations.push_back(arrToken[i].GetTextToken());
					if (arrOperations[arrOperations.size() - 2] == "+")
					{
						arrWords[arrWords.size() - 2] = arrWords[arrWords.size() - 2] + arrWords[arrWords.size() - 1];
					}
					else
					{
						error("efsfge");
					}
					arrWords.pop_back();
					arrOperations[arrOperations.size() - 2] = arrOperations[arrOperations.size() - 1];
					arrOperations.pop_back();
				}
			}
			else if (arrToken[i].GetNameTokenType() == "VARIABLE")
			{
				for (int j = 0; j < arrVariable.size(); j++)
				{
					if (arrVariable[j].GetName() == arrToken[i].GetTextToken())
					{
						if (arrVariable[j].GetDataType() == "string")
						{
							arrWords.push_back(arrVariable[j].GetMean());
							break;
						}
						else
						{
							error("afefs90j");
						}
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
			if (i == end - 1)
			{
				if (arrToken[i].GetNameTokenType() == "TEXT" or arrToken[i].GetNameTokenType() == "VARIABLE")
				{
					//arrNum.push_back(stoi(arrToken[i].GetTextToken()));
					if (arrOperations.size() >= 1)
					{
						for (int j = arrOperations.size() - 1; j >= 0; j--)
						{
							if (arrOperations[j] == "+")
							{
								arrWords[arrWords.size() - 2] = arrWords[arrWords.size() - 2] + arrWords[arrWords.size() - 1];
							}
							else
							{
								error("afefs90j");
							}
							arrWords.pop_back();
							//arrOperations.pop_back();
						}
					}
				}

			}
		}

		return arrWords[0];
	}
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
						else if (arrOperations[arrOperations.size() - 2] == "<")
						{
							if (arrNum[arrNum.size() - 2] < arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "<=")
						{
							if (arrNum[arrNum.size() - 2] <= arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "==")
						{
							if (arrNum[arrNum.size() - 2] == arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == ">=")
						{
							if (arrNum[arrNum.size() - 2] >= arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == ">")
						{
							if (arrNum[arrNum.size() - 2] > arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "AND")
						{
							if (arrNum[arrNum.size() - 2] == 1 and arrNum[arrNum.size() - 1] == 1)
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "OR")
						{
							if (arrNum[arrNum.size() - 2] == 1 or arrNum[arrNum.size() - 1] == 1)
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						arrNum.pop_back();
						arrOperations[arrOperations.size() - 2] = arrOperations[arrOperations.size() - 1];
						arrOperations.pop_back();

					}
				}
				
			}
			else if (arrToken[i].GetNameTokenType() == "COMPARISON" or arrToken[i].GetTextToken() == "OR" or arrToken[i].GetTextToken() == "AND")
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
						else if (arrOperations[arrOperations.size() - 2] == "<")
						{
							if (arrNum[arrNum.size() - 2] < arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "<=")
						{
							if (arrNum[arrNum.size() - 2] <= arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "==")
						{
							if (arrNum[arrNum.size() - 2] == arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == ">=")
						{
							if (arrNum[arrNum.size() - 2] >= arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == ">")
						{
							if (arrNum[arrNum.size() - 2] > arrNum[arrNum.size() - 1])
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "AND")
						{
							if (arrNum[arrNum.size() - 2] == 1 and arrNum[arrNum.size() - 1] == 1)
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
						}
						else if (arrOperations[arrOperations.size() - 2] == "OR")
						{
							if (arrNum[arrNum.size() - 2] == 1 or arrNum[arrNum.size() - 1] == 1)
							{
								arrNum[arrNum.size() - 2] = 1;
							}
							else
							{
								arrNum[arrNum.size() - 2] = 0;
							}
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
						if (arrVariable[j].GetDataType() == "int")
						{
							arrNum.push_back(stoi(arrVariable[j].GetMean()));
							break;
						}
						else if (arrVariable[j].GetDataType() == "string")
						{
							// решение проблемы с лог опер со строками
							int k1 = i;
							while (arrToken[k1].GetTextToken() != "==")
							{
								k1++;
							}
							int k2 = k1 + 1;

							while (true)
							{
								if (arrToken[k2].GetNameTokenType() == "RIGHTPARENTHESIS" or arrToken[k2].GetTextToken() == "OR" or arrToken[k2].GetTextToken() == "AND")
								{
									
									break;
								}
								k2++;
							}
							if (ExpressionAnalyzerString(arrToken, i, k1) == ExpressionAnalyzerString(arrToken, k1 + 1, k2)) // здесь что то не так с переменными i k1 k2
							{
								arrNum.push_back(1);
							}
							else
							{
								arrNum.push_back(0);
							}
							i = k2-1;
							break;
						}
						else
						{
							error("afefs90j");
						}
					}
					if (j == arrVariable.size() - 1 and arrVariable[j].GetName() != arrToken[i].GetTextToken())
					{
						error("asfdse");
					}
				}
			}
			else if (arrToken[i].GetNameTokenType() == "TEXT")
			{
				// решение проблемы с лог опер со строками
				int k1 = i;
				while (arrToken[k1].GetTextToken() != "==")
				{
					k1++;
				}
				int k2 = k1 + 1;

				while (true)
				{
					if (arrToken[k2].GetNameTokenType() == "RIGHTPARENTHESIS" or arrToken[k2].GetTextToken() == "OR" or arrToken[k2].GetTextToken() == "AND")
					{
						
						break;
					}
					k2++;
				}
				if (ExpressionAnalyzerString(arrToken, i, k1) == ExpressionAnalyzerString(arrToken, k1 + 1, k2))
				{
					arrNum.push_back(1);
				}
				else
				{
					arrNum.push_back(0);
				}
				i = k2-1;
				break;
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
							else if (arrOperations[j] == "<")
							{
								if (arrNum[arrNum.size() - 2] < arrNum[arrNum.size() - 1])
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == "<=")
							{
								if (arrNum[arrNum.size() - 2] <= arrNum[arrNum.size() - 1])
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == "==")
							{
								if (arrNum[arrNum.size() - 2] == arrNum[arrNum.size() - 1])
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == ">=")
							{
								if (arrNum[arrNum.size() - 2] >= arrNum[arrNum.size() - 1])
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == ">")
							{
								if (arrNum[arrNum.size() - 2] > arrNum[arrNum.size() - 1])
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == "AND")
							{
								if (arrNum[arrNum.size() - 2] == 1 and arrNum[arrNum.size() - 1] == 1)
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == "OR")
							{
								if (arrNum[arrNum.size() - 2] == 1 or arrNum[arrNum.size() - 1] == 1)
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							arrNum.pop_back();
							//arrOperations.pop_back();
						}
					}
				}
				else if (arrToken[i].GetNameTokenType() == "TEXT" or arrToken[i].GetNameTokenType() == "VARIABLE")
				{
					if (arrOperations.size() >= 1)
					{
						for (int j = arrOperations.size() - 1; j >= 0; j--)
						{
							if (arrOperations[j] == "AND")
							{
								if (arrNum[arrNum.size() - 2] == 1 and arrNum[arrNum.size() - 1] == 1)
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							else if (arrOperations[j] == "OR")
							{
								if (arrNum[arrNum.size() - 2] == 1 or arrNum[arrNum.size() - 1] == 1)
								{
									arrNum[arrNum.size() - 2] = 1;
								}
								else
								{
									arrNum[arrNum.size() - 2] = 0;
								}
							}
							arrNum.pop_back();
						}
					}
				}
				/*else if ()
				{
				// решение проблемы с лог опер со строками
				int k1 = i;
				while (arrToken[k1].GetTextToken() != "==")
				{
					k1++;
				}
				int k2 = k1 + 2;

				while (arrToken[k2].GetNameTokenType() != "RIGHTPARENTHESIS" or arrToken[k2].GetTextToken() != "OR" or arrToken[k2].GetTextToken() != "AND")
				{
					k2++;
				}
				if (ExpressionAnalyzerString(arrToken, i, k1) == ExpressionAnalyzerString(arrToken, k1 + 2, k2))
				{
					arrNum.push_back(1);
				}
				else
				{
					arrNum.push_back(0);
				}
				i = k2 + 1;
				}*/
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


	void syntAnalyzer(vector <Token> arrToken, int start, int end)
	{
		for (int i = start; i < end; i++)
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
						if (arrToken[i].GetTextToken() == "string")
						{
							arrVariable.push_back(Variable(arrToken[i + 1].GetTextToken(), ExpressionAnalyzerString(arrToken, i + 3, j), arrToken[i].GetTextToken()));
						}
						else if (arrToken[i].GetTextToken() == "int")
						{
							arrVariable.push_back(Variable(arrToken[i + 1].GetTextToken(), to_string(mathExpressionAnalyzerInt(arrToken, i + 3, j)), arrToken[i].GetTextToken()));
						}
						i = j;
						//funcmath
					}
					else if (arrToken[i + 2].GetNameTokenType() == "SEMICOLON")
					{
						arrVariable.push_back(Variable(arrToken[i + 1].GetTextToken(), "0", arrToken[i].GetTextToken()));
						i = i + 2;
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
			else if (arrToken[i].GetNameTokenType() == "VARIABLE" and arrToken[i - 1].GetNameTokenType() != "DATATYPE")
			{
				if (arrToken[i + 1].GetNameTokenType() == "ASSIGN")
				{
					for (int j = 0; j < arrVariable.size(); j++)
					{
						if (arrVariable[j].GetName() == arrToken[i].GetTextToken())
						{
							int k = i + 2;
							while (arrToken[k].GetNameTokenType() != "SEMICOLON")
							{
								k++;
							}
							
							

							/**/
							if (arrToken[i + 2].GetNameTokenType() == "TEXT")
							{
								arrVariable[j].SetMean(ExpressionAnalyzerString(arrToken, i+2, k));
							}
							else if (arrToken[i + 2].GetNameTokenType() == "NUMBER")
							{
								arrVariable[j].SetMean(to_string(mathExpressionAnalyzerInt(arrToken, i+2, k)));
							}
							else if (arrToken[i + 2].GetNameTokenType() == "VARIABLE")
							{
								for (int l = 0; l < arrVariable.size(); l++)
								{
									if (arrVariable[l].GetName() == arrToken[i + 2].GetTextToken())
									{
										if (arrVariable[l].GetDataType() == "string")
										{
											arrVariable[j].SetMean(ExpressionAnalyzerString(arrToken, i + 2, k));
											break;
										}
										else if (arrVariable[l].GetDataType() == "int")
										{
											arrVariable[j].SetMean(to_string(mathExpressionAnalyzerInt(arrToken, i + 2, k)));
											break;
										}
										else
										{
											error("afefs90j");
										}
									}
									else if (l == arrVariable.size() - 1 and arrVariable[l].GetName() != arrToken[l].GetTextToken())
									{
										error("asfdse");
									}
								}
							}
							/**/


							i = k;
							break;
						}
						else if (j == arrVariable.size() - 1 and arrVariable[j].GetName() != arrToken[i].GetTextToken())
						{
							error("asfdse1");
						}
					}
				}
			}
			else if (arrToken[i].GetNameTokenType() == "KEYWORDS")
			{
				if (arrToken[i].GetTextToken() == "LOG")
				{
					int j = i+1;
					while (arrToken[j].GetNameTokenType() != "SEMICOLON")
					{
						j++;
					}
					if (arrToken[i + 1].GetNameTokenType() == "TEXT")
					{
						cout << ExpressionAnalyzerString(arrToken, i + 1, j) << endl;
					}
					else if (arrToken[i + 1].GetNameTokenType() == "NUMBER")
					{
						cout << mathExpressionAnalyzerInt(arrToken, i + 1, j) << endl;
					}
					else if (arrToken[i + 1].GetNameTokenType() == "VARIABLE")
					{
						for (int k = 0; k < arrVariable.size(); k++)
						{
							if (arrVariable[k].GetName() == arrToken[i+1].GetTextToken())
							{
								if (arrVariable[k].GetDataType() == "string")
								{
									cout << ExpressionAnalyzerString(arrToken, i + 1, j) << endl;
									break;
								}
								else if (arrVariable[k].GetDataType() == "int")
								{
									cout << mathExpressionAnalyzerInt(arrToken, i + 1, j) << endl;
									break;
								}
								else
								{
									error("afefs90j");
								}
							}
							else if (k == arrVariable.size() - 1 and arrVariable[k].GetName() != arrToken[k].GetTextToken())
							{
								error("asfdse");
							}
						}
					}
					
					i = j;
				}
				else if (arrToken[i].GetTextToken() == "IF")
				{
					if (arrToken[i + 1].GetNameTokenType() == "LEFTPARENTHESIS")
					{
						int j = i + 2;
						while(arrToken[j].GetNameTokenType() != "RIGHTPARENTHESIS")
						{
							j++;
						}
						if (mathExpressionAnalyzerInt(arrToken, i+2, j) == 1)   // проблема тут
						{
							i = j;
							while (arrToken[i].GetNameTokenType() != "RIGHTCURLYBRACES")
							{
								i++;
							}
							syntAnalyzer(arrToken, j, i);
						}
						else
						{
							i = j;
							while (arrToken[i].GetNameTokenType() != "RIGHTCURLYBRACES")
							{
								i++;
							}
						}

					}
					else
					{
						error("error: ожидается '('");
					}
				}

			}


		}
	}
};
