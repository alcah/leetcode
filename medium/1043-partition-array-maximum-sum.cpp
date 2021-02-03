// 1043-partition-array-maximum-sum.cpp
// 2021-01-25


// Given an integer array arr, you should partition the array into (contiguous)
// subarrays of length at most k. After partitioning, each subarray has their
// values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		vector<int> dp(arr.size());
		int localmax = 0;

		for (int i = 0; i < (int)arr.size(); i++) {
			localmax = 0;
			for (int j = 1; j <= k && i-j+1 >= 0; j++) {
				localmax = max(localmax, arr[i-j+1]);
				dp[i] = max(dp[i], (i - j >= 0 ? dp[i-j] : 0) + localmax * j);
			}
		}

		return dp[arr.size()-1];
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
