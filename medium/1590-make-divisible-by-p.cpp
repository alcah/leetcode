// 1590-make-divisible-by-p.cpp
// 2021-01-28
// START: 21:00:00
// END:

// Given an array of positive integers nums, remove the smallest subarray
// (possibly empty) such that the sum of the remaining elements is divisible by
// p. It is not allowed to remove the whole array.

// Return the length of the smallest subarray that you need to remove, or -1 if
// it's impossible.

// A subarray is defined as a contiguous block of elements in the array.

// Example 1:

// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible by
// 6. We can remove the subarray [4], and the sum of the remaining elements is
// 6, which is divisible by 6.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minSubarray(vector<int>& nums, int p)
	{
		// TODO
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> arr = {3, 1, 4, 2};
	cout << s.minSubarray(arr, 6) << endl;
	return 0;
}
