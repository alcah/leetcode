// 456-132-pattern.CPO
// 2021-01-13

// Given an array of n integers nums, a 132 pattern is a subsequence of three
// integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] <
// nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

// Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the
// O(n) solution?


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums)
	{
		if (nums.size() < 3) { return false; }
		stack<int> s;
		vector<int> minj(nums.size(), 0);

		for (int i = 0; i < (int)nums.size(); i++)
			{ minj[i] = min(minj[i-1], nums[i]); }

		for (int j = nums.size() - 1; j >= 0; j--) {
			// minj[j] is guaranteed to be a lower index than j
			if (nums[j] > minj[j]) {
				while (!s.empty() && s.top() <= minj[j])
					{ s.pop(); }
				if (!s.empty() && s.top() < nums[j])
					{ return true; }
				s.push(nums[j]);
			}
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {1, 2, 3, 4};
	cout << s.find132pattern(nums) << endl;
	return 0;
}
