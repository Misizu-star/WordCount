#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "wordCount.h"
using namespace std;

wordsCount::wordsCount() {    }
wordsCount::wordsCount(string path) :PATH(path) {    }
void wordsCount::SetPath(string path) {
	PATH = path;
}
int wordsCount::Char_num() {
	ifstream file;
	file.open(PATH);
	if (!file.is_open()) {
		throw "File con't open!";
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
int wordsCount::Lines_num() {
	ifstream file;
	file.open(PATH);
	if (!file.is_open()) {
		throw "File con't open!";
	}
	int line_num = 0;
	while (!file.eof()) {
		string temp_line = "";
		getline(file, temp_line);
		line_num++;
	}
	file.close();
	return line_num;
}
int wordsCount::Words_num() {
	if (Words_rate.empty())
		this->Sort_words_rate();
	return Words_rate.size();
}
void wordsCount::GetWords() {
	ifstream file;
	file.open(PATH, ios::in | ios::out);
	if (!file.is_open()) {
		throw "File con't open!";
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
						Words.push_back(temp_word);
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
					Words.push_back(temp_word);
				}
				temp_word = "";
				letter_num = 0;
			}
		}
	}
	file.close();
}
void wordsCount::Sort_words_rate() {
	if (Words.empty())
		this->GetWords();
	vector<string> words = Words;
	sort(words.begin(), words.end());
	pair<string, int> temp_words;
	for (int i = 0; i < words.size(); i++) {
		if (Words_rate.empty() || Words_rate[Words_rate.size() - 1].first.compare(words[i])) {
			temp_words.first = words[i];
			temp_words.second = 1;
			Words_rate.push_back(temp_words);
		}
		else {
			Words_rate[Words_rate.size() - 1].second++;
		}
	}
	sort(Words_rate.begin(), Words_rate.end(), cmp);
}
void wordsCount::Sort_group_rate(int m) {
	if (Words.empty())
		this->GetWords();
	vector<string> group;
	for (int i = 0; i < Words.size() - m + 1; i++) {
		string temp = "";
		for (int j = 0; j < m; j++)
			temp += Words[i + j] + " ";
		group.push_back(temp);
	}
	sort(group.begin(), group.end());
	for (int i = 0; i < group.size(); i++) {
		pair<string, int> temp_pair;
		temp_pair.first = group[i];
		temp_pair.second = 1;
		if (Words_group.empty() || group[i].compare((Words_group.end() - 1)->first)) {
			Words_group.push_back(temp_pair);
		}
		else
			(Words_group.end() - 1)->second++;
		sort(Words_group.begin(), Words_group.end(), cmp);
	}
}
string wordsCount::Show_most_word(const int n) {
	if (Words_rate.empty())
		this->Sort_words_rate();
	string io = "\n最多的前";
	io += to_string(n) + "个单词\n";
	cout << "\n最多的前" << n << "个单词：" << endl;
	int i = n;
	for (auto p = Words_rate.begin(); p != Words_rate.end() && i > 0; p++, i--) {
		cout << p->first << endl;
		io += p->first + "\n";
	}
	return io;
}
string wordsCount::ShowWords_rate() {
	if (Words_rate.empty())
		this->Sort_words_rate();
	int count = 1;
	string io = "\n前十个词频最高的单词：\n";
	cout << "\n前十个词频最高的单词：" << endl;
	for (auto p = Words_rate.begin(); p != Words_rate.end() && count <= 10; p++, count++) {
		cout << "<" << p->first << ">: " << p->second << endl;
		io += "<" + p->first + ">: ";
		io += to_string(p->second) + "\n";
	}
	return io;
}
string wordsCount::ShowGroup_rate(const int m) {
	if (Words_group.empty())
		this->Sort_group_rate(m);
	string io = "\n长度为";
	io += to_string(m) + "的词组：\n";
	cout << "\n长度为" << m << "的词组：" << endl;
	for (auto p = Words_group.begin(); p != Words_group.end(); p++) {
		cout << p->first << ": " << p->second << endl;
		io += p->first + ": ";
		io += to_string(p->second) + "\n";
	}
	return io;
}
void Getop(int argc, char *argv[], vector<string> &operation) {
	for (int i = 1; i < argc; i++) {
		string temp = "";
		temp += argv[i];
		operation.push_back(temp);
	}
}
bool cmp(pair<string, int>a, pair<string, int>b) {
	return a.second > b.second;
}
