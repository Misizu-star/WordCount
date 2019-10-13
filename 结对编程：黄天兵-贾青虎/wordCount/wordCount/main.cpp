#include <iostream>
#include <string>
#include "wordCount.h"

using namespace std;

int main() {
	string path;
	cin >> path;
	wordsCount my(path);
	vector<string> words;
	vector<pair<string, int>> word_rate;
	try {
		my.GetWords(words);
		word_rate = my.Sort_byRate(words);
		cout << "characters: " << my.Characters() << endl;
		cout << "words: " << word_rate.size() << endl;
		cout << "lines: " << my.Lines() << endl;
		cout << endl;
		int count = 0;
		for (auto p = word_rate.begin(); p != word_rate.end() && count <= 10; p++) {
			cout << "<" << p->first << ">: " << p->second << endl;
			count++;
		}
	}
	catch (const int error) {
		if (error == 0) {
			cerr << "文件不存在或位置已变更" << endl;
		}
	}
	return 0;
}