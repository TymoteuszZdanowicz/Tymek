export module CreateWordleDatabase;
import <iostream>;
import <fstream>;
import <ranges>;
import <filesystem>;

using namespace std;
using namespace filesystem;

export class CreateWordleDatabase {
public:
	path languages_folder = "languages";

	virtual vector<string> loadWords() = 0;
	virtual string selectWinningWord(ranges::ref_view<vector<string>> words) = 0;
};