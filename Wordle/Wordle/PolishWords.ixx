export module PolishWords;
export import CreateWordleDatabase;
import <iostream>;
import <fstream>;
import <ranges>;
import <filesystem>;
import <random>;

using namespace std;
using namespace filesystem;

export class PolishWords : public CreateWordleDatabase
{
public:
	PolishWords() {
		languages_folder += "\\polskie_slowa.txt";
	}

	vector<string> loadWords() {
		vector<string> polish_words;
		string line;
		ifstream file(languages_folder);

		if (file.is_open()) {
			ranges::copy(ranges::istream_view<string>(file), back_inserter(polish_words));
			file.close();
		}
		else {
			cerr << "Couldn't find file" << endl;
		}
		return polish_words;
	}

	string selectWinningWord(ranges::ref_view<vector<string>> words) {
		random_device rd;  
		mt19937 gen(rd()); 
		uniform_int_distribution<> dist(1, words.size());

		int random = dist(gen);
		return words[random];
	}

	~PolishWords() {

	}
};