// 560-subarray-sum-equals-k.cpp
// 2021-01-28
// START: 23:25:12
// END: 18:00:50 -- the next day

// Given an array of integers nums and an integer k, return the total number of
// continuous subarrays whose sum equals to k.

// Input: nums = [1,1,1], k = 2
// Output: 2

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k)
	{
		// why can't I use a set?? Why's it important to keep track of the
		// number of occurrences?

		// because if negative numbers are allowed then there can be multiple
		// way to reduce the subarray to form the same sum -- therefore we have
		// to count both.
		unordered_map<int, int> sums = {{0, 1}};
		int res = 0;
		int sum = 0;

		for (int i = 0; i < (int)nums.size(); ++i) {
			sum += nums[i];
			// if sum-k is in the map it means that sum can be formed by
			// removing that sub array from the one we're currently looking at
			if (sums.count(sum-k)) { res += sums[sum-k]; }
			sums[sum]++;
		}
		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> arr = {0, 1, 3, 4, 7};
	cout << s.subarraySum(arr, 3) << endl;
	return 0;
}
