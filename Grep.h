#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class Grep
{
public:
	Grep(bool testN, bool testL, bool testV, bool testA, std::vector<std::string> fileName, std::string hladaneSlovo, int posRiad);
	void vykonaj();
	virtual ~Grep();
};

