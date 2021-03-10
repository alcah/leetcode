// 215-kth-largest-element-array.cpp
// 2021-03-01

// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return quickselect(nums, 0, nums.size(), k);
	}

	int partition(vector<int> &nums, int lo, int hi)
	{
		int pivot = lo;
		int i = hi+1;

		// i chases j
		for (int j = hi; j > lo; j--) {
			if (nums[j] >= nums[pivot]) {
				swap(nums[--i], nums[j]);
			}
		}
		swap(nums[--i], nums[pivot]);

		// final index of pivot
		return i;
	}

	int quickselect(vector<int> &nums, int lo, int hi, int k)
	{
		if (lo >= hi) { return lo; }

		int p = partition(nums, lo, hi);
		if (p == k) { return nums[p]; }
		else if (p > k) { return quickselect(nums, lo, p-1, k); }
		else { return quickselect(nums, p+1, hi, k); }
	}
};
