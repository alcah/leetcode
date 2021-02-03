#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>

using namespace std;

// The Hamming distance between two integers is the number of positions at which
// the corresponding bits are different.

// Now your job is to find the total Hamming distance between all pairs of the
// given numbers.

class Solution {
public:
	int totalHammingDistance(vector<int>& nums)
	{
		// goes through digit by digit counting how much each adds to the total
		// hamming distance
		// log(m) loops where m is the highest digit count in nums
		int sum = 0;
		int n0 = 0;
		int n1 = 0;
		int shift = 0;
		bool finished = false;

		while (!finished) {
			finished = true;
			n0 = n1 = 0;
			for (auto n : nums) {
				if (((n >> shift) & 1) == 1) { n1++; }
				else { n0++; }
				if (n >> shift) { finished = false; }
			}
			sum += n0 * n1;
			shift++;
		}
		return sum;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {4, 14, 2};
	cout << s.totalHammingDistance(nums) << endl;
	return 0;
}
