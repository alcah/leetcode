// remove-duplicate-letters.cpp
// 2021-01-27

// Given a string s, remove duplicate letters so that every letter appears once
// and only once. You must make sure your result is the smallest in
// lexicographical order among all possible results.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		int occur[26] = {0};
		string res;
		for (char c : s) {
			occur[c - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (occur[i]) { res.push_back('a'+i); }
		}
		return res;
	}
};
