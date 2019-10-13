#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "wordCount.h"
using namespace std;

wordsCount::wordsCount() {    }
wordsCount::wordsCount(string path) :PATH(path) {    }
int wordsCount::Characters() {
	ifstream file;
	file.open(PATH);
	if (!file.is_open()) {
		throw 0;
	}
	int char_num = 0;
	while (1) {
		if (file.eof())
			break;
		else {
			char ch = file.get();
			if (ch >= 0 && ch <= 127)
				char_num++;
		}
	}
	file.close();
	return char_num;
}
int wordsCount::Lines() {
	ifstream file;
	file.open(PATH);
	if (!file.is_open()) {
		throw 0;
	}
	int line_num = 0;
	while (1) {
		if (file.eof())
			break;
		string temp_line = "";
		getline(file, temp_line);
		line_num++;
	}
	file.close();
	return line_num;
}
void wordsCount::GetWords(vector<string> &words) {
	ifstream file;
	file.open(PATH);
	if (!file.is_open()) {
		throw 0;
	}
	string temp_word = "";
	int letter_num = 0;
	while (1) {
		if (file.eof())
			break;
		else {
			char ch = file.get();
			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
				if (temp_word == "") {
					temp_word += ch;
					letter_num++;
				}
				else {
					char last_char = temp_word.at(temp_word.size() - 1);
					if (last_char >= '0'&&last_char <= '9'&&letter_num >= 4) {
						transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
						words.push_back(temp_word);
						temp_word = "";
						letter_num = 0;
					}
					else {
						temp_word += ch;
						letter_num++;
					}
				}
			}
			else if (ch >= '0'&&ch <= '9'&&temp_word != "") {
				temp_word += ch;
			}
			else {
				if (letter_num >= 4) {
					transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
					words.push_back(temp_word);
				}
				temp_word = "";
				letter_num = 0;
			}
		}
	}

	file.close();
}
vector<pair<string, int>> wordsCount::Sort_byRate(vector<string> &words) {
	vector<pair<string, int>> word_rate;
	sort(words.begin(), words.end());
	pair<string, int> temp_words;
	for (int i = 0; i < words.size(); i++) {
		if (word_rate.empty() || word_rate[word_rate.size() - 1].first.compare(words[i])) {
			temp_words.first = words[i];
			temp_words.second = 1;
			word_rate.push_back(temp_words);
		}
		else {
			word_rate[word_rate.size() - 1].second++;
		}
	}
	words.clear();
	for (int i = 0; i < word_rate.size(); i++) {
		words.push_back(word_rate[i].first);
	}
	sort(word_rate.begin(), word_rate.end(), cmp);
	return word_rate;
}
bool cmp(pair<string, int>a, pair<string, int>b) {
	return a.second > b.second;
}
