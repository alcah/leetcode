// TODO: Currently doesn't work
// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:

// Return true if there exists i, j, k
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:

// Input: [1,2,3,4,5]
// Output: true
// Example 2:

// Input: [5,4,3,2,1]
// Output: false


class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) { return false; }

		int i = nums[0];
		int j = INT_MAX, k = INT_MAX;

		for (int n : nums) {
			if (nums[n] > i && j == INT_MAX) { j = nums[n]; }
			else if (nums[n] > j && k == INT_MAX) { k = nums[n]; }

			if (j != INT_MAX && k != INT_MAX) { return true; }
		}

		i = j = k = INT_MAX;
		i = nums[nums.size()-1];

		for (auto n : nums.rbegin()) {
			if (nums[n] < i && j == INT_MAX) { j = nums[n]; }
			else if (nums[n] < j && k == INT_MAX) { k = nums[n]; }

			if (j != INT_MAX && k != INT_MAX) { return true; }
		}
		return false;
	}
};
