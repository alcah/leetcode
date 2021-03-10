// 435-non-overlapping-intervals.cpp
// 2021-02-28

// Given a collection of intervals, find the minimum number of intervals you
// need to remove to make the rest of the intervals non-overlapping.

// Example 1:

// Input: [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of intervals are
// non-overlapping.  Example 2:

// Input: [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of intervals
// non-overlapping.  Example 3:

// Input: [[1,2],[2,3]] Output: 0
// Explanation: You don't need to remove any of the intervals since they're
// already non-overlapping.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		int taken = 0;
		int ending = 0;
		auto f = [](vector<int> &a, vector<int> &b) {
			return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
		};

		sort(intervals.begin(), intervals.end(), f);

		// always take interval ending soonest
		for (int i = 0; i < (int)intervals.size(); i++) {
			if (intervals[i][0] >= ending) {
				taken++;
				ending = intervals[i][0];
			}
		}
			return (intervals.size() - taken);
	}
};
