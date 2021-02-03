#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>

using namespace std;

// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Follow up: Do not use any built-in library function such as sqrt.

class Solution {
public:
	bool isPerfectSquare(int num)
	{
		// binary search from 0 to num for a number x such that x*x = num
		int l = 0, r = num;
		long long x;
		while (l <= r) {
			x = (l+r) / 2;
			if (x*x > num) {
				r = x - 1;
			}
			else if (x*x < num) {
				l = x + 1;
			}
			else { return x; }
		}

		return false;
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	cout << (s.isPerfectSquare(16) ? "true" : "false") << endl;
	cout << (s.isPerfectSquare(14) ? "true" : "false") << endl;
	cout << (s.isPerfectSquare(1) ? "true" : "false") << endl;
	cout << (s.isPerfectSquare(100) ? "true" : "false") << endl;
	cout << (s.isPerfectSquare(1000052909) ? "true" : "false") << endl;
	return 0;
}
