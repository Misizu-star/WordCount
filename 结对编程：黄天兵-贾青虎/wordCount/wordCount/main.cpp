#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "wordCount.h"

using namespace std;

int main(int argc, char *argv[]) {
	wordsCount test;
	try {
		if (argc == 2) {
			test.SetPath(argv[1]);
			cout << "\ncharacters: " << test.Char_num() << endl;
			cout << "words: " << test.Words_num() << endl;
			cout << "lines: " << test.Lines_num() << endl;
			test.ShowWords_rate();
		}
		else if (argc > 2 && argc % 2 == 1) {
			ofstream file;
			vector<string> cmd;
			Getop(argc, argv, cmd);
			auto p = find(cmd.begin(), cmd.end(), "-i");
			auto q = find(cmd.begin(), cmd.end(), "-o");
			if (p != cmd.end() && q != cmd.end()) {
				test.SetPath(*(p + 1));
				file.open(*(q + 1));
				if (!file.is_open()) {
					throw "File can't open!";
				}
				cout << "characters: " << test.Char_num() << endl;
				cout << "words: " << test.Words_num() << endl;
				cout << "lines: " << test.Lines_num() << endl;
				file << "characters: " << test.Char_num() << endl;
				file << "words: " << test.Words_num() << endl;
				file << "lines: " << test.Lines_num() << endl;
				p = find(cmd.begin(), cmd.end(), "-n");
				q = find(cmd.begin(), cmd.end(), "-m");
				if (p != cmd.end()) {
					file << test.Show_most_word(stoi(*(p + 1)));
				}
				if (q != cmd.end()) {
					file << test.ShowGroup_rate(stoi(*(q + 1)));
				}
			}
			else
				throw "������������� -i �� -o ";
		}
		else      //��������Ϊ0�����2��ż��ʱ�׳��쳣
			throw "��������ȷ����";
	}
	catch (const char *msg) {
		cerr << msg << endl;
	}
	catch (invalid_argument&) {
		//����stoi()�׳����쳣
		cerr << "-m��-n������������" << endl;
	}
	catch (out_of_range&) {
		//����stoi()�׳����쳣
		cerr << "�������볬����Χ" << endl;
	}
	return 0;
}