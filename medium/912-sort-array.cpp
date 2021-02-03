// 912-sort-array.cpp
// 2021-02-02

// Given an array of integers nums, sort the array in ascending order.


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums)
	{
		// supposing numbers are in random order, there's no reason not to pick
		// the first as the pivot point
		quicksort(nums, 0, nums.size()-1);
		return nums;
	}

	// return index of pivot element in NUMS within [LO, HI] in its final
	// sorted position.
	// partition NUMS between LO and HI such that all elements greater than the
	// pivot have a greater index and vice versa
	int partition(vector<int> &nums, int lo, int hi)
	{
		int pivot = lo;
		int i = hi+1;

		// it's important that i chases j, otherwise the sorting won't be
		// correct
		for (int j = hi; j > lo; j--) {
			if (nums[j] >= nums[pivot]) {
				swap(nums[--i], nums[j]);
			}
		}
		swap(nums[--i], nums[pivot]);

		// final index of pivot
		return i;
	}

	void quicksort(vector<int> &nums, int lo, int hi)
	{
		int p = 0;
		if (lo >= hi) { return; }

		p = partition(nums, lo, hi);
		quicksort(nums, lo, p - 1);
		quicksort(nums, p + 1, hi);
	}
};
