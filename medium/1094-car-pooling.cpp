// 1094-car-pooling.cpp
// 2021-02-15

// You are driving a vehicle that has capacity empty seats initially available
// for passengers.  The vehicle only drives east (ie. it cannot turn around and
// drive west.)

// Given a list of trips, trip[i] = [num_passengers, start_location,
// end_location] contains information about the i-th trip: the number of
// passengers that must be picked up, and the locations to pick them up and drop
// them off.  The locations are given as the number of kilometers due east from
// your vehicle's initial location.

// Return true if and only if it is possible to pick up and drop off all
// passengers for all the given trips.

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//	bool carPooling(vector<vector<int>>& trips, int capacity)
//	{
//		unordered_map<int, int> end;
//		int maxdest = 0;

//		for (auto &t : trips) {
//			start[t[1]] += t[0];
//			end[t[2]] += t[0];
//			maxdest = max(maxdest, t[2]);
//		}

//		// iterate through car positions
//		for (int i = 0; i <= maxdest; i++) {
//			if (end.count(i) != 0) { capacity += end[i]; }
//			if (start.count(i) != 0) { capacity -= start[i]; }
//			if (capacity < 0) { return false; }
//		}
//		return true;
//	}
// };

// bucketsort
class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity)
	{
		vector<int> time(1001, 0);
		for (auto &t : trips) {
			time[t[1]] += t[0];
			time[t[2]] -= t[0];
		}

		// iterate through car positions
		for (int t : time) {
			if ((capacity += t) < 0) { return false; }
		}
		return true;
	}
};
