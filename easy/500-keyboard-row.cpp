// 500-keyboard-row.cpp
// 2021-01-09

// Given a List of words, return the words that can be typed using letters of
// alphabet on only one row's of American keyboard like the image below.
// STARTTIME: 20:09:30
// ENDTIME:


#include <bits/stdc++.h>
#include <cmath>
#include <locale>
#include <stdio.h>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words)
	{
		vector<string> r;
		unordered_set<char> top =
			{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
		unordered_set<char> middle =
			{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
		unordered_set<char> bottom =
			{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
		unordered_set<char> *row = &top;

		for (auto w : words) {
			if (top.find(tolower(w[0])) != top.end()) { row = &top; }
			else if (middle.find(tolower(w[0])) != middle.end()) { row = &middle; }
			else { row = &bottom; }
			if (onRow(w, *row)) { r.push_back(w); }
		}
		return r;
	}

	bool onRow(string &word, unordered_set<char> &row)
	{
		cout << word <<":\n";
		for (char c : word) {
			printf("%c, %c\n", c, tolower(c));
			if (row.find(tolower(c)) == row.end()) {
				return false;
			}
		}
		cout << "returning true \n";
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> words = {"Hello", "Alaska", "Dad", "Fish"};
	for (auto w :	s.findWords(words)) {
		cout << w << endl;
	}
	return 0;
}
