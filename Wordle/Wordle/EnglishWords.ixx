export module EnglishWords;
export import CreateWordleDatabase;
import <iostream>;
import <fstream>;
import <ranges>;
import <filesystem>;
import <random>;

using namespace std;
using namespace filesystem;

export class EnglishWords : public CreateWordleDatabase
{
public:
	EnglishWords() {
		languages_folder += "\\sgb-words.txt";
	}

	vector<string> loadWords() {
		vector<string> english_words;
		string line;
		ifstream file(languages_folder);

		if (file.is_open()) {
			ranges::copy(ranges::istream_view<string>(file), back_inserter(english_words));
			file.close();
		}
		else {
			cerr << "Couldn't find file" << endl;
		}
		return english_words;
	}

	string selectWinningWord(ranges::ref_view<vector<string>> words) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, words.size());

		int random = dist(gen);
		return words[random];
	}

	~EnglishWords() {

	}
};