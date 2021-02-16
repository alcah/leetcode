// 394-decode-string.cpp
// 2021-02-13
// TOPIC: Parsing

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces,
// square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any
// digits and that digits are only for those repeat numbers, k. For example,
// there won't be input like 3a or 2[4].

#include <bits/stdc++.h>
#include <regex>

using namespace std;


class Solution {
public:
	string decodeString(string s)
	{
		string res = "";
		string rep = "";
		string str = "";
		int depth = 0;

		for (int i = 0; i < (int)s.size();) {
			rep = "";
			str = "";
			depth = 0;
			// repetition counter
			if (isdigit(s[i])) {
				while (i < (int)s.size() && isdigit(s[i])) {
					rep += s[i++];
				}
				// read string enclosed in []
				// [
				i++;
				while (!(depth == 0 && s[i] == ']')) {
					if (s[i] == '[') { depth++; }
					else if (s[i] == ']') { depth--; }
					str += s[i++];
				}
				// ]
				i++;
				cout << str << " " << rep << endl;
				res += repeat(decodeString(str), stoi(rep));
			}
			// letter
			else {
				res += s[i++];
			}
		}
		return res;
	}

	string repeat(string s, int n)
	{
		string res = "";
		for (int i = 0; i < n; i++) {
			res += s;
		}
		return res;
	}
};
