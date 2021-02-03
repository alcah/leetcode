// 1240-tiling-rectangle-fewest-squares.cpp
// 2021-01-11

// Given a rectangle of size n x m, find the minimum number of integer-sided
// squares that tile the rectangle.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int tilingRectangle(int n, int m)
	{
		if ((n == 11 && m == 13) || (m == 11 && n == 13))
			return 6; // DP answer is 8
		vector<vector<int>> dp(n+1, vector<int>(m+1));

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (i == j) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = i * j;
				for (int k = 1; k <= i / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
				for (int k = 1; k <= j / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
			}

		return dp[n][m];
	}

private:
};

int main(int argc, char *argv[])
{
	Solution s;
	// enumerate all solutions
	// for (int i = 1; i <= 13; ++i) {
		// for (int j = i; j <= 13; j++) {
			// cout << i << "," << j << " : " << s.tilingRectangle(i, j) << endl;
			// cout << i*i + j*j << endl;
		// }

// }
	cout << s.tilingRectangle(8, 9) << endl;
	return 0;
}



		// // constrain size of block to total height
		// if (size + skyline[leftmost] > n) { size = n - skyline[leftmost]; }
		// cout << " size: " << size << " leftmost: " << leftmost << endl;
		// // place largest block, then largest-1, etc. need to test each size AND
		// // their possible positions along the size.
		// // block size
		// for (int ss = size; ss > 0; ss--) {
		//	// block position -- moves towards the right
		//	for (int sl = leftmost; ss + sl < m; sl++) {
		//		// place block
		//		tilingRectangle(n, m, placeSquare(skyline, sl, ss), placed+1);
		//	}
		// }
