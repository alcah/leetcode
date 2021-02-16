// 692-top-k-frequent-words.cpp
// 2021-02-14
// TOPIC: Heap

// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two
// words have the same frequency, then the word with the lower alphabetical
// order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		auto f = [](pair<int, string> a, pair<int, string> b) {
			return (a.first < b.first) ||
				(a.first == b.first && a.second > b.second);
		};
		unordered_map<string, int> freq;
		priority_queue<pair<int, string>,
					   vector<pair<int, string>>,
					   decltype(f)>
			q(f);
		vector<string> res;

		for (string w : words) {
			freq[w]++;
		}

		for (auto w : freq) {
			q.push({w.second, w.first});
		}

		for (; k > 0; k--) {
			res.push_back(q.top().second);
			q.pop();
		}
		return res;
	}
};
