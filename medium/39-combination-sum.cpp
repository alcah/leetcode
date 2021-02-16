// 39-combination-sum.cpp
// 2021-02-05
// LEARNT: Consider how order can be imposed on a problem

// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of
// times. Two combinations are unique if the frequency of at least one of the
// chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target
// is less than 150 combinations for the given input.

// closely modelled off the change counting problem, but we want to collect
// every solution. Maybe there's a way to do this bottom-up DP, but I don't see
// it.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<int> chosen = {};
		f(candidates, chosen, target, 0);
		return res;
	}

	void f(vector<int> &candidates, vector<int> &chosen, int target, int first)
	{
		if (target == 0) {
			res.push_back(chosen);
			return;
		}

		for (int i = first; i < (int)candidates.size() &&
				 target >= candidates[i]; i++) {
			chosen.push_back(candidates[i]);
			f(candidates, chosen, target - candidates[i], i);
			chosen.pop_back();
		}
		return;
	}

private:
	vector<vector<int>> res;
};
