#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

void wypisz(int start) {
	for (int i = start - 1; i < 10; i++) {
		cout << start + i << endl;
	}
}

// Define a function to sort a portion of the array
void sortSubarray(vector<int>& arr, int start, int end) {
	sort(arr.begin() + start, arr.begin() + end + 1);
}

// Define a function to sort an array using threads
void sortArrayWithThreads(vector<int>& arr, int numThreads) {
	int chunkSize = arr.size() / numThreads;
	int start, end;

	vector<thread> threads(numThreads);
	for (int i = 0; i < numThreads; i++) {
		start = i * chunkSize;
		if (i == numThreads - 1) {
			end = arr.size() - 1;
		}
		else {
			end = start + chunkSize - 1;
		}
		threads[i] = thread(sortSubarray, ref(arr), start, end);
	}

	for (auto& t : threads) {
		t.join();
	}
}




int main() {
	thread t1(wypisz, 1);
	thread t100(wypisz, 100);
	
	t1.join();
	t100.join();


	vector<int> arr = { 5, 3, 7, 1, 8, 2, 9, 4, 6, 10 };

	sortArrayWithThreads(arr, 2);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
	// fizzbuzz
	// modelio 