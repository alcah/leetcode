// 931-minimum-falling-path-sum.cpp
// 2021-02-04
// START: 16:16:33
// END: 16:41:22
// TOPIC: DP

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		int smallest;

		// set first row
		for (int j = 0; j < n; ++j) {
			dp[0][j] = matrix[0][j];
		}

		for(int i = 1; i < n; i++) {
			for (int j = 0; j < (int)matrix[0].size(); j++) {
				smallest = INT_MAX;
				if (j - 1 >= 0) { smallest = min(smallest, dp[i-1][j-1]); }
				if (j + 1 < n) { smallest = min(smallest, dp[i-1][j+1]); }
				smallest = min(smallest, dp[i-1][j]);

				dp[i][j] = smallest + matrix[i][j];
			}
		}

		// pick final smallest
		smallest = dp[n-1][0];
		cout << dp[n-1][0] << endl;
		for (int j = 1; j < n; j++) {
			smallest = min(smallest, dp[n-1][j]);
			cout << dp[n-1][j] << endl;
		}
		return smallest;
	}
};

int main(int argc, char *argv[])
{

	return 0;
}
