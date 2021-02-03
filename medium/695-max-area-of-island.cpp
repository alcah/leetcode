// 695-max-area-of-island.cpp
// 2021-01-29
// START: 21:52:43
// END: 22:08:10
// TOPIC: Searching
// LEARNT: DFS is a fair bit faster than BFS for this sort of thing

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid)
	{
		vector<vector<bool>> seen(grid.size(),
								  vector<bool>(grid[0].size(), false));
		int maxarea = 0;

		for (int i = 0; i < (int)grid.size(); i++) {
			for (int j = 0; j < (int)grid[0].size(); j++) {
				if (grid[i][j] == 1 && !seen[i][j]) {
					maxarea = max(maxarea, dfs(i, j, grid, seen));
				}
			}
		}
		return maxarea;
	}
	int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &seen)
	{
		static vector<pair<int,int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		int size = 1;
		seen[i][j] = true;
		int x, y;

		for (auto a : adj) {
			y = a.first + i;
			x = a.second + j;
			if (y >= (int)grid.size() || y < 0 ||
				x >= (int)grid[0].size() || x < 0 ||
				grid[y][x] == 0 || seen[y][x])
				{ continue; }
			size += dfs(y, x, grid, seen);
		}
		return size;
	}

	int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &seen)
	{
		static vector<pair<int,int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		queue<pair<int, int>> q;
		pair<int,int> p;
		int x, y;
		int size = 1;

		q.push({i, j});
		seen[i][j] = true;

		while (!q.empty()) {
			p = q.front();
			q.pop();

			for (auto a : adj) {
				y = a.first + p.first;
				x = a.second + p.second;
				if (y >= (int)grid.size() || y < 0 ||
					x >= (int)grid[0].size() || x < 0 ||
					grid[y][x] == 0 || seen[y][x])
					{ continue; }
				seen[y][x] = true;
				q.push({y, x});
				size++;
			}
		}
		return size;
	}
};

int
main(int argc, char *argv[])
{
	return 0;
}
