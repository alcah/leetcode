// 90-subsets-ii.cpp
// 2021-02-16
// START: 11:36:55
// END: 12:22:00
// LEARNT: powerset (set of all subsets)


// Given an integer array nums that may contain duplicates, return all possible
// subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in
// any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// can be represented with bits
// leaves the problem of finding duplicates
// could put them into a set

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		const int n = nums.size();
		vector<vector<int>> res;
		set<vector<int>> subsets;
		vector<int> subset;

		sort(nums.begin(), nums.end());

		auto p = nums.begin();
		// generate all subsets
		for (int i = 0; i < (1 << n); i++) {
			subset = {};
			p = nums.begin();
			for (int j = i; j > 0; j >>= 1) {
				if (j & 1) { subset.push_back(*p); }
				p += 1;
			}
			subsets.insert(subset);
		}

		// convert to vector
		for (auto s : subsets) {
			res.push_back(s);
		}

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
