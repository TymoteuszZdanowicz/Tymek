#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <codecvt>

using namespace std;

class CreateWordleDatabase {
public:
	virtual vector<string> loadWords() = 0;
	virtual string selectWinningWord() = 0;
};
