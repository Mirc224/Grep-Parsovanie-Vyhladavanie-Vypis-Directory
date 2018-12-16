#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include "Grep.h"
namespace fs = std::filesystem;


int main(int argc, char* argv[])
{
	int posRiad = 0;
	bool testN = false;
	bool testL = false;
	bool testV = false;
	bool testA = false;
	std::vector<std::string> fileName;
	std::string hladaneSlovo = "";

	//std::string directory;
	//std::string filename = "C:\\Users\\mino\\source\\repos\\DomacaUloha2\\DomacaUloha2\\DomacaUloha2";
	//const size_t last_slash_idx = filename.rfind('\\');
	//if (std::string::npos != last_slash_idx)
	//{
	//	directory = filename.substr(0, last_slash_idx);
	//}

	for (int i = 1; i < argc; ++i)
	{
		std::string docasnyString = argv[i];
		if (docasnyString.find("*") != std::string::npos)
		{
			docasnyString = docasnyString.substr(docasnyString.find("*")+1);
			if (docasnyString.find(".txt") != std::string::npos)
			{
				std::string path = "./";
				for (auto & p : std::filesystem::directory_iterator(path))
				{
					std::string hladanySubor = p.path().filename().string();
					if(hladanySubor.find(docasnyString) != std::string::npos)
						std::cout << p.path().filename() << std::endl;
				}
			}
		}
		if (docasnyString.at(0) == '-')
		{
			int j = 1;
			switch (docasnyString.at(1))
			{
			case 'n': testN = true;
				break;
			case 'l': testL = true;
				break;
			case 'v': testV = true;
				break;
			case 'a': posRiad = docasnyString.at(2) - '0';
				testA = true;
				break;
			default:
				break;

			}
		}
		else if (docasnyString.at(0) == '\"' || docasnyString.at(0) == '\'')
		{
			int j = 1;
			while ((docasnyString.at(j) != '\"') && (docasnyString.at(j) != '\''))
			{
				hladaneSlovo += docasnyString.at(j);
				++j;
			}
		}
		else if (docasnyString.find(".txt"))
		{
			fileName.push_back(docasnyString);
		}
	}
	Grep(testN,testL,testV,testA,fileName,hladaneSlovo,posRiad);
	return 0;
}




//std::vector<std::string> zoSKdeSN; //zoznam kde sa nachadza
//for (auto &nazovSuboru : fileName)
//{
//	std::ifstream inputFile(nazovSuboru);
//	std::string newLine;
//	std::string riadokVypisu = "";
//	int j = 1;
//	bool test = true;
//	while (std::getline(inputFile, newLine)) // odstrani \n
//	{
//		if (!testV)
//		{
//			if (newLine.find(hladaneSlovo) != std::string::npos)
//			{
//				if (test)
//				{
//					zoSKdeSN.push_back(nazovSuboru);
//					test = false;
//				}
//				if (!testL)
//				{
//					if (testN)
//					{
//						if (fileName.size() > 1)
//							std::cout << nazovSuboru << ": " << j << " " << newLine << std::endl;
//						else
//							std::cout << j << " " << newLine << std::endl;
//					}
//					else
//					{
//						if (fileName.size() > 1)
//							std::cout << nazovSuboru << ": " << newLine << std::endl;
//						else
//							std::cout << " " << newLine << std::endl;
//						for (int i = 0; i < posRiad; ++i)
//						{
//							std::cout << std::endl;
//						}
//					}
//				}

//			}
//		}
//		else
//		{
//			if (newLine.find(hladaneSlovo) == std::string::npos)
//			{
//				if (test)
//				{
//					zoSKdeSN.push_back(nazovSuboru);
//					test = false;
//				}
//				if (!testL)
//				{
//					if (testN)
//					{
//						if (fileName.size() > 1)
//							std::cout << nazovSuboru << ": " << j << " " << newLine << std::endl;
//						else
//							std::cout << j << " " << newLine << std::endl;
//					}
//					else
//					{
//						if (fileName.size() > 1)
//							std::cout << nazovSuboru << ": " << newLine << std::endl;
//						else
//							std::cout << " " << newLine << std::endl;
//						for (int i = 0; i < posRiad; ++i)
//						{
//							std::cout << std::endl;
//						}
//							
//					}
//				}
//			}
//		}

//		++j;
//	}
//}
//if (testL)
//{
//	for (auto &vypis : zoSKdeSN)
//		std::cout << vypis << std::endl;
//}

















//std::string testCast = "\"slovo\"";
//if (testCast.at(0) == '\"' || testCast.at(0) == '\'')
//{
//	{
//		int i = 1;
//		while ((testCast.at(i) != '\"') && (testCast.at(i) != '\''))
//		{
//			hladaneSlovo += testCast.at(i);
//			++i;
//		}
//	}
//	std::vector<int> cisloRiadku;
//	std::vector<std::string> riadokSlova;
//	std::string fileName = "uloha1.txt";
//	std::ifstream inputFile(fileName);
//	std::string newLine;
//	int j = 1;
//	while (std::getline(inputFile, newLine)) // odstrani \n
//	{

//		if (newLine.find(hladaneSlovo) != std::string::npos)
//		{
//			std::cout << fileName << ": "<< j << " " << newLine << std::endl;
//		}
//		++j;
//	}
//}
//std::cout << hladaneSlovo;