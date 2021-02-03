// 201. Bitwise AND of Numbers Range
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
// of all numbers in this range, inclusive.

// Example 1:

// Input: [5,7]
// Output: 4
// Example 2:

// Input: [0,1]
// Output: 0

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		if (m == n) { return m; }
		int msb = 0;
		int mask = 0;
		while (m >= (msb = mostSignificantBit(n))) {
			mask += msb;
			m >>= 1;
			n >>= 1;
		}
		return mask;
	}

	// 1 line solution -- extremely genius
	// int rangeBitwiseAnd(int m, int n) {
	//	return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
	// }

	int mostSignificantBit(int n)
	{
		if (n == 0)
			return 0;

		int msb = 0;
		n = n / 2;
		while (n != 0) {
			n = n / 2;
			msb++;
		}

		return (1 << msb);
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.rangeBitwiseAnd(5, 7) << endl;
	cout << s.rangeBitwiseAnd(0, 2147483647) << endl;
	// cout << s.mostSignificantBit(56) << endl;
	// cout << s.mostSignificantBit(1161) << endl;
	return 0;
}
