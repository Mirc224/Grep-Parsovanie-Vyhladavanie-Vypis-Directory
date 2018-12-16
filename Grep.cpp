#include "Grep.h"



Grep::Grep(bool testN, bool testL, bool testV, bool testA, std::vector<std::string> fileName , std::string hladaneSlovo,int posRiad)
{
	std::vector<std::string> zoSKdeSN; //zoznam kde sa nachadza
	for (auto &nazovSuboru : fileName)
	{
		std::ifstream inputFile(nazovSuboru);
		std::string newLine;
		std::string riadokVypisu = "";
		int j = 1;
		bool test = true;
		while (std::getline(inputFile, newLine)) // odstrani \n
		{
			if (!testV)
			{
				if (newLine.find(hladaneSlovo) != std::string::npos)
				{
					if (test)
					{
						zoSKdeSN.push_back(nazovSuboru);
						test = false;
					}
					if (!testL)
					{
						if (testN)
						{
							if (fileName.size() > 1)
								std::cout << nazovSuboru << ": " << j << " " << newLine << std::endl;
							else
								std::cout << j << " " << newLine << std::endl;
						}
						else
						{
							if (fileName.size() > 1)
								std::cout << nazovSuboru << ": " << newLine << std::endl;
							else
								std::cout << " " << newLine << std::endl;
							for (int i = 0; i < posRiad; ++i)
							{
								std::cout << std::endl;
							}
						}
					}

				}
			}
			else
			{
				if (newLine.find(hladaneSlovo) == std::string::npos)
				{
					if (test)
					{
						zoSKdeSN.push_back(nazovSuboru);
						test = false;
					}
					if (!testL)
					{
						if (testN)
						{
							if (fileName.size() > 1)
								std::cout << nazovSuboru << ": " << j << " " << newLine << std::endl;
							else
								std::cout << j << " " << newLine << std::endl;
						}
						else
						{
							if (fileName.size() > 1)
								std::cout << nazovSuboru << ": " << newLine << std::endl;
							else
								std::cout << " " << newLine << std::endl;
							for (int i = 0; i < posRiad; ++i)
							{
								std::cout << std::endl;
							}

						}
					}
				}
			}

			++j;
		}
	}
	if (testL)
	{
		for (auto &vypis : zoSKdeSN)
			std::cout << vypis << std::endl;
	}
}

void Grep::vykonaj()
{
}


Grep::~Grep()
{
}
