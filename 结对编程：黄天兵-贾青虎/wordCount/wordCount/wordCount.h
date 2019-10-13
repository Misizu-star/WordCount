#pragma once
#include <string>
#include <vector>
using namespace std;

class wordsCount {
public:
	wordsCount();
	wordsCount(string path);
	void SetPath(string path);
	int Char_num();
	int Lines_num();
	int Words_num();
	string Show_most_word(int n);
	string ShowWords_rate();
	string ShowGroup_rate(int m);
private:
	string PATH;
	vector<string>Words;
	vector<pair<string, int>> Words_rate;
	vector<pair<string, int>> Words_group;
	void GetWords();
	void Sort_words_rate();
	void Sort_group_rate(int m);
};
bool cmp(pair<string, int>a, pair<string, int>b);
void Getop(int argc, char *argv[], vector<string> &operation);