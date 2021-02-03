// 200-number-of-islands.cpp
// 2021-01-07

// Given an m x n 2d grid map of '1's (land) and '0's (water), return the number
// of islands.

// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int nislands = 0;
		vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
		for (int i = 0; i < (int)grid.size(); ++i) {
			for (int j = 0; j < (int)grid[0].size(); ++j) {
				if (!(seen[i][j]) && grid[i][j] == '1') {
					bfs(grid, seen, {i, j});
					nislands++;
				}
			}
		}
		return nislands;
	}

	void bfs(vector<vector<char>> &grid, vector<vector<bool>> &seen, pair<int,int> s)
	{
		queue<pair<int,int>> q;
		static const vector<pair<int,int>> adjacent =
			{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		int ax = 0, ay = 0;
		pair<int,int> p;

		q.push(s);
		seen[s.first][s.second] = true;

		while (!q.empty()) {
			p = q.front();
			q.pop();
			// for each adjacent node
			for (auto a : adjacent) {
				ay = a.first + p.first;
				ax = a.second + p.second;
				if (ay < (int)grid.size() && ay >= 0 &&
					ax < (int)grid[0].size() && ax >= 0 &&
					grid[ay][ax] == '1' && !(seen[ay][ax])) {
					seen[ay][ax] = true;
					q.push({ay, ax});
				}
			}
		}
	}
};

int main(int argc, char *argv[])
{
	vector<vector<char>> v = {{'1','1','1','1','1','1','1'}};
	Solution s;
	cout << s.numIslands(v) << endl;
	return 0;
}
