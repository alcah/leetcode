// 75-sort-colours.cpp
// 2021-01-29
// START: 18:21:15
// END: 18:31:42
// TOPIC: Counting Sort, Partitioning
// LEARNT: Dutch Flag Problem

// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums)
	{
		// counting sort
		int count[3] = {0};

		for (int c : nums) {
			count[c]++;
		}

		for (int i = 0; i < (int)nums.size(); i++) {
			nums[i] = (count[0]-- > 0 ? 0 : (count[1]-- > 0 ? 1 : 2));
		}
		return;
	}
};

class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		// Dutch flag partitioning
		int lo, mid, hi;
		lo = mid = 0;
		hi = nums.size()-1;

		while (mid <= hi) {
			if (nums[mid] == 0) {
				swap(nums[mid], nums[lo]);
				mid++;
				lo++;
			}
			else if (nums[mid] == 1) {
				mid++;
			}
			else {
				swap(nums[mid], nums[hi]);
				hi--;
			}
		}
		return;
	}

private:

};

int main(int argc, char *argv[])
{

	return 0;
}
