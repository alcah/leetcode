// 17-letter-combinations-phone.cpp
// 2021-01-31
// START:
// END:

// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order.

// A mapping of digit to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.

#include <bits/stdc++.h>

using namespace std;

// bitmask
// class Solution {
// public:
//	vector<string> letterCombinations(string digits)
//	{
//		vector<string> res;
//		string word = "";
//		int nbits = digits.size() * 2;

//		for (int i = 0; i < (1 << nbits); i++) {
//			if ((word = bin2string(i, digits)) != "")
//				{ res.push_back(word); }
//		}
//		return res;
//	}

//	// returns string corresponding to N; else empty string if invalid
//	string bin2string(int n, string &digits)
//	{
//		int charidx = 0;
//		string word = "";

//		for (int j = 0; j < (int)digits.size(); j++) {
//			charidx = n & ((1 << 2) - 1);
//			if (charidx >= (int)letters[digits[j] - '0'].size())
//				{ return ""; }
//			word.push_back(letters[digits[j] - '0'][charidx]);
//			n = n >> 2;
//		}
//		return word;
//	}
// private:
	// vector<string> letters =
		// { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// };

// backtracking
class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		this->digits = digits;
		f(0, "");
		return res;
	}

	void f(int digit, string word)
	{
		if (digit >= (int)digits.size()) {
			res.push_back(word);
			return;
		}

		for (char c : letters[digits[digit] - '0']) {
			word.push_back(c);
			f(digit + 1, word);
			word.pop_back();
		}
		return;
	}

private:
	string digits;
	vector<string> res;
	vector<string> letters =
		{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

};


int main(int argc, char *argv[])
{
	Solution s;
	for (string st : s.letterCombinations("999")) {
		cout << st << endl;
	}
	return 0;
}
