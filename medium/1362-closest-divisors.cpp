#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>

using namespace std;

// Given an integer num, find the closest two integers in absolute difference
// whose product equals num + 1 or num + 2.

// Return the two integers in any order.

// find divisors of num+1 and num+2
// only need to iterate up to sqrt(num)


class Solution {
public:
	vector<int> closestDivisors(int num) {
		auto f = [](pair<int,int> p1, pair<int,int> p2) {
			if (abs(p1.first - p1.second) <
				abs(p2.first - p2.second))
			{ return p1; } else { return p2; }};
		auto fnp1 = factorPairs(num + 1);
		auto fnp2 = factorPairs(num + 2);
		auto a = accumulate(fnp1.begin(), fnp1.end(), pair<int,int>(INT_MAX, 0), f);
		auto b = accumulate(fnp2.begin(), fnp2.end(), pair<int,int>(INT_MAX, 0), f);
		vector<pair<int,int>> mins = {a, b};
		auto min = accumulate(mins.begin(), mins.end(), pair<int,int>(INT_MAX, 0), f);
		return {min.first, min.second};
	}

	// return all factor pairs of n
	vector<pair<int,int>> factorPairs(int n)
	{
		vector<pair<int,int>> factors;
		double q = sqrt(n);
		for (int i = 1; i <= q; i++) {
			if (n % i == 0) {
				factors.push_back({i, n/i});
			}
		}
		return factors;
	}

};

int main(int argc, char *argv[])
{
	Solution s;
	auto one = s.closestDivisors(123);
	auto nine = s.closestDivisors(999);
	cout << "123: " << one[0] << one[1] << endl;
	cout << "999: " << nine[0] << nine[1] << endl;
	return 0;
}
