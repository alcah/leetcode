#include <bits/stdc++.h>

using namespace std;

// Given a m x n grid. Each cell of the grid represents a street. The street of
// grid[i][j] can be:
// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0,0). A valid
// path in the grid is a path which starts from the upper left cell (0,0) and
// ends at the bottom-right cell (m - 1, n - 1). The path should only follow the
// streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.

class Solution {
public:
	// dummy value makes indexing neater
	pair<pair<int,int>,pair<int,int>> tiles[7] = {{{0,0},{0,0}},
												  {{0, -1}, {0, 1}},
												  {{-1, 0}, {1, 0}},
												  {{0, -1}, {1, 0}},
												  {{0, 1},  {1, 0}},
												  {{0, -1}, {-1, 0}},
												  {{-1, 0}, {0, 1}}};
	bool hasValidPath(vector<vector<int>>& grid)
	{
		if (tryPath(grid, tiles[grid[0][0]].first) ||
			tryPath(grid, tiles[grid[0][0]].second))
			{ return true; }

		return false;
	}

	bool tryPath(vector<vector<int>>& grid, pair<int,int> origin)
	{
		vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
		int x = 0, y = 0;
		int nx = 0, ny = 0;
		pair<int,int> next = {0,0};
		while (y != (int)grid.size()-1 || x != (int)grid[0].size()-1) {
			seen[y][x] = true;
			// get direction that isn't the origin
			next = (tiles[grid[y][x]].first == origin) ?
				tiles[grid[y][x]].second : tiles[grid[y][x]].first;
			nx = x + next.second;
			ny = y + next.first;
			if (ny < 0 || ny >= (int)grid.size() ||
				nx < 0 || nx >= (int)grid[0].size() ||
				seen[ny][nx] ||
				!(validPath(next, grid[ny][nx])))
			{ return false; }

			origin = {-(next.first), -(next.second)};
			x = nx;
			y = ny;
		}
		return true;
	}

	// return t if there's a valid path from direction o to t; else false
	bool validPath(pair<int,int> o, int t)
	{
		auto dir1 = tiles[t].first;
		auto dir2 = tiles[t].second;

		if (dir1.first + o.first == 0 && dir1.first + o.first == 0)
		{ return true; }
		if (dir2.first + o.first == 0 && dir2.first + o.first == 0)
		{ return true; }
		return false;
	}
};

int main(int argc, char *argv[])
{
	vector<vector<int>> grid1 = {{1,1,2}}; // false
	vector<vector<int>> grid2 = {{4,1},{6,1}}; // true
	vector<vector<int>> grid3 = {{4,3,3},{6,5,2}}; // false
	Solution s;
	cout << (s.hasValidPath(grid1) ? "true\n" : "false\n");
	cout << (s.hasValidPath(grid2) ? "true\n" : "false\n");
	cout << (s.hasValidPath(grid3) ? "true\n" : "false\n");
	return 0;
}
