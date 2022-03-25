#include <iostream>
#include "Counter.h"

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
	int getcnt(int cnt) {
		return cnt;
	}
	int setcnt(int cnt) {
		this->cnt = cnt;
	}

};