// 712-minimum-ascii-delete-distance.cpp
// 2021-03-08

// Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
// make two strings equal.

// Example 1: Input: s1 = "sea", s2 = "eat" Output: 231 Explanation: Deleting
// "s" from "sea" adds the ASCII value of "s" (115) to the sum.  Deleting "t"
// from "eat" adds 116 to the sum.  At the end, both strings are equal, and 115
// + 116 = 231 is the minimum sum possible to achieve this.  Example 2: Input:
// s1 = "delete", s2 = "leet" Output: 403 Explanation: Deleting "dee" from
// "delete" to turn the string into "let", adds 100[d]+101[e]+101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.  At the end, both strings
// are equal to "let", and the answer is 100+101+101+101 = 403.  If instead we
// turned both strings into "lee" or "eet", we would get answers of 433 or 417,
// which are higher.  Note:

// 0 < s1.length, s2.length <= 1000.  All elements of each string will have an
// ASCII value in [97, 122].


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumDeleteSum(string s1, string s2)
	{
		// add 1 to dimensions to account for empty strings
		vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

		// last column; s2 is empty string
		for (int i = s1.size() - 1; i >= 0; --i) {
			dp[i][s2.size()] = dp[i+1][s2.size()] + s1[i];
		}
		// last row; s1 is empty string
		for (int j = s2.size()-1; j >= 0; --j) {
			dp[s1.size()][j] = dp[s1.size()][j+1] + s2[j];
		}

		// min for each cell is the min of right or down
		// or diag right down if characters are the same and can be ignored
		for (int i = s1.size()-1; i >= 0; --i) {
			for (int j = s2.size()-1; j >= 0; --j) {
				if (s1[i] == s2[j]) { dp[i][j] = dp[i+1][j+1]; }
				else {
					dp[i][j] = min(dp[i+1][j] + s1[i],
								   dp[i][j+1] + s2[j]);
				}
			}
		}
		return dp[0][0];
	}
};
