// You have a list of words and a pattern, and you want to know which words in
// words matches the pattern.

// A word matches the pattern if there exists a permutation of letters p so that
// after replacing every letter x in the pattern with p(x), we get the desired
// word.

// (Recall that a permutation of letters is a bijection from letters to letters:
// every letter maps to another letter, and no two letters map to the same
// letter.)

// Return a list of the words in words that match the given pattern.

// You may return the answer in any order.


#include <bits/stdc++.h>

using namespace std;
// Normalise both strings to the same format
class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern)
	{
		vector<string> r;
		pattern = normalise(pattern);
		for (string w : words) {
			if (normalise(w) == pattern) { r.push_back(w); }
		}
		return r;
	}

	string normalise(string word)
	{
		unordered_map<char, int> m;
		int inc = 0;
		for (char c : word) {
			if (!m.count(c)) { m[c] = inc++; }
		}
		for (int i = 0; i < (int)word.size(); ++i)
			{ word[i] = 'a' + m[word[i]]; }
		return word;
	}
};

// create character mapping
// class Solution {
// public:
//	vector<string> findAndReplacePattern(vector<string>& words, string pattern)
//	{
//		vector<string> r;
//		for (string w : words) {
//			if (match(w, pattern)) { r.push_back(w); }
//		}
//		return r;
//	}

//	bool match(const string &word, const string &pattern)
//	{
//		unordered_map<char, char> wordalist;
//		unordered_map<char, char> patternalist;

//		for (int i = 0; i < (int)word.size(); i++) {
//			// neither character in alist
//			if (wordalist.find(word[i]) == wordalist.end() &&
//				patternalist.find(pattern[i]) == patternalist.end()) {
//				// associate with eachother; continue
//				wordalist[word[i]] = pattern[i];
//				patternalist[pattern[i]] = word[i];
//				continue;
//			}

//			// characters map to eachother
//			if (wordalist[word[i]] == pattern[i] &&
//				patternalist[pattern[i]] == word[i])
//				{ continue; }

//			// else either one is in the list and the other isn't or they don't
//			// map to eachother -- all false
//			return false;
//		}
//		return true;
//	}
// };

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
	for (auto s : s.findAndReplacePattern(words, "abb")) {
		cout << s << endl;
	}
	return 0;
}
