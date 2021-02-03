#include <bits/stdc++.h>

using namespace std;

// There are n flights, and they are labeled from 1 to n.

// We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k]
// means that we booked k seats from flights labeled i to j inclusive.

// Return an array answer of length n, representing the number of seats booked
// on each flight in order of their label.

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		// sweep line
		vector<int> r(n + 1, 0);

		for (auto f : bookings) {
			r[f[0] - 1] += f[2];
			r[f[1]] -= f[2];
		}

		for (int i = 1; i < n; ++i) {
			r[i] += r[i-1];
		}

		return {r.begin(), r.end()-1};
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int>> flights = {{1,2,10},{2,3,20},{2,5,25}};

	for (auto f : s.corpFlightBookings(flights, 5)) {
		cout << f << endl;
	}

	return 0;
}
