#pragma once
#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>

using namespace std;

class Counter {
	int cnt;
public:
	Counter() {
		cnt = 1;
		cout << "git" << endl;
	}
	Counter(int cnt) {
		this->cnt = cnt;
		cout << "also git" << endl;
	}
	int getcnt() {
		return cnt;
	}
	bool setcnt(int cnt) {
		this->cnt = cnt;
		return 1;
	}

	bool operator =(Counter cos) {
		this->cnt = cos.getcnt();
		cout << "cos.operator=()" << endl;
		return this;
	}

	int operator +(int dod) {
		return (this->cnt + dod);
	}

	bool operator +=(int dod) {
		this->cnt += dod;
		return 1;
	}

	int operator ()(int ink) {
		return this->cnt += ink;
	}

	int operator ~() {
		return this->cnt -= 2 * this->cnt;
	}

	int operator ++() {
		return this->cnt + 1;
	}



};
#endif 
