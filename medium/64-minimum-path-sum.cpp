// 64-minimum-path-sum.cpp
// 2021-01-27

// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100

#include <bits/stdc++.h>

using namespace std;

// dynamic programming solution since the graph is a DAG
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		// dp[y][x] = grid[y][x] + min(dp[y-1][x], dp[y][x-1])
		// can be done in-place without the dp array.
		// better not to mutate input grid
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		// fill in special cases where x-1 or y-1 don't exist
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			dp[i][0] = grid[i][0] + dp[i-1][0];
		}
		for (int j = 1; j < n; j++) {
			dp[0][j] = grid[0][j] + dp[0][j-1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
			}
		}
		return dp[m-1][n-1];
	}
};

// In-place without the dp array.
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		// dp[y][x] = grid[y][x] + min(dp[y-1][x], dp[y][x-1])
		int m = grid.size();
		int n = grid[0].size();

		// fill in special cases where x-1 or y-1 don't exist
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			grid[i][0] = grid[i][0] + grid[i-1][0];
		}
		for (int j = 1; j < n; j++) {
			grid[0][j] = grid[0][j] + grid[0][j-1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
			}
		}
		return grid[m-1][n-1];
	}
};
