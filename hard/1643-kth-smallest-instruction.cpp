// 1643-kth-smallest-instruction.cpp
// 2021-02-02

// Bob is standing at cell (0, 0), and he wants to reach destination: (row,
// column). He can only travel right and down. You are going to help Bob by
// providing instructions for him to reach destination.

// The instructions are represented as a string, where each character is either:

// 'H', meaning move horizontally (go right), or 'V', meaning move vertically
// (go down).  Multiple instructions will lead Bob to destination. For example,
// if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.

// However, Bob is very picky. Bob has a lucky number k, and he wants the kth
// lexicographically smallest instructions that will lead him to destination. k
// is 1-indexed.

// Given an integer array destination and an integer k, return the kth
// lexicographically smallest instructions that will take Bob to destination.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string kthSmallestPath(vector<int>& destination, int k)
	{

		string res;
		int v = destination[0];
		int h = destination[1];
		vector<vector<int>> binom(v + h + 1, vector<int>(v + 1, -1));

		// prefill table
		choose(v + h, v, binom);
		while (v > 0 || h > 0) {
			if (h == 0) {
				res += string(v, 'V');
				break;
			}
			if (v == 0) {
				res += string(h, 'H');
				break;
			}
			if (k > choose(v + h - 1, v, binom)) {
				res.push_back('V');
				k -= choose(v + h -1, v, binom);
				v--;

			}
			else {
				res.push_back('H');
				h--;
			}
		}
		return res;
	}

	int choose(int n, int k, vector<vector<int>> &dp)
	{
		if (dp[n][k] != -1) { return dp[n][k]; }
		if (k == 0 || k == n) {
			dp[n][k] = 1;
			return dp[n][k];
		}

		dp[n][k] = choose(n-1, k-1, dp) + choose(n-1, k, dp);
		return dp[n][k];
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> dest = {2, 3};
	cout << s.kthSmallestPath(dest, 1) << endl;
	return 0;
}
