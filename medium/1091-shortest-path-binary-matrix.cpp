// 1091-shortest-path-binary-matrix.cpp
// 2021-01-08


// In an N by N square grid, each cell is either empty (0) or blocked (1).

// A clear path from top-left to bottom-right has length k if and only if it is
// composed of cells C_1, C_2, ..., C_k such that:

// Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
// different and share an edge or corner)
// C_1 is at location (0, 0) (ie. has value grid[0][0])
// C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
// If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
// Return the length of the shortest such clear path from top-left to
// bottom-right.  If such a path does not exist, return -1.


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		// Dijkstra's algorithm
		// Dijkstra's on an unweighted graph is identical to breadth-first
		// search.
		const vector<pair<int,int>> adjacent = {{-1, -1}, {-1, 0}, {-1, 1},
												{0, -1}, {0, 1},
												{1, -1}, {1, 0}, {1, 1}};
		vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
		queue<tuple<int, int, int>> q;
		int p = INT_MAX, y = 0, x = 0;
		int ay = 0, ax = 0;

		q.push({0, 0, 1});
		seen[0][0] = true;

		while (!q.empty()) {
			tie(p, y, x) = q.front();
			q.pop();

			for (auto a : adjacent) {
				ay = y + a.first;
				ax = x + a.second;
				if (ay >= 0 && ay < (int)grid.size() &&
					ax >= 0 && ax < (int)grid[0].size() &&
					grid[ay][ax] == 0 && !(seen[ay][ax])) {

					seen[ay][ax] = true;
					q.push({p+1, ay, ax});
					if (ax == (int)grid[0].size() - 1 && ay == (int)grid.size() - 1) {
						return p + 1;
					}
				}
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int>> matrix = {{0,0,0},{1,1,0},{1,1,0}};
	cout << s.shortestPathBinaryMatrix(matrix) << endl;
	return 0;
}
