#pragma once
#include <string>
#include <vector>
using namespace std;

class wordsCount {
public:
	wordsCount();
	wordsCount(string path);
	int Characters();
	int Lines();
	void GetWords(vector<string> &words);
	vector<pair<string, int>> Sort_byRate(vector<string> &words);
private:
	string PATH;
};
bool cmp(pair<string, int>a, pair<string, int>b);