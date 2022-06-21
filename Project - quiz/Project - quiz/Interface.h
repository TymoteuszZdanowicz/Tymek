#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include "ParseFile.h"
#include "Question.h"

using namespace std;

class Interface{
public:
	vector<Question> pytania;
	double sumaPunktow, otrzymanePunkty = 0;
	int iloscPytan;
	time_t beginTime, endTime;
	string start;
	Interface(vector<Question> pytania, double sumaPunktow, int iloscPytan);

	void nauka();
	void test();
	void wybor();
	void Start(int n);
};
