#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
	{
		// flood from ocean, take intersection of sets
		vector<vector<int>> pacific = oceanFlood(false, matrix);
		vector<vector<int>> atlantic = oceanFlood(true, matrix);
		vector<vector<int>> r;

		set_intersection(pacific.begin(), pacific.end(), atlantic.begin(), atlantic.end(),
						 back_inserter(r));
		return r;
	}

	vector<vector<int>>
	adjacent(int x, int y, vector<vector<int>>& matrix)
	{
		int xsize = matrix.size();
		int ysize = matrix[0].size();
		vector<vector<int>> r;

		for (int i = x - 1; i <= x + 1; i++) {
			if (!(i < 0 || i >= xsize)) {
				r.push_back({i, y});
			}
		}
		for (int j = y - 1; j <= y + 1; j++) {
			if (!(j < 0 || j >= ysize)) {
				r.push_back({x, j});
			}
		}
		return r;
	}

	vector<vector<int>> oceanFlood(bool atlantic, vector<vector<int>>& matrix)
	{
		// BFS with all pacific connected cells on the queue
		int xsize = matrix.size();
		int ysize = matrix[0].size();
		vector<vector<bool>> seen(xsize, vector<bool>(ysize, false));
		queue<vector<int>> q;
		vector<int> p;
		vector<vector<int>> r;

		if (atlantic) {
			for (int i = 0; i < xsize; i++) {
				q.push({i, ysize-1});
				seen[i][ysize-1] = true;
			}
			for (int j = 0; j < ysize; j++) {
				q.push({xsize-1, j});
				seen[xsize-1][j] = true;
			}
		} else {
			for (int i = 0; i < xsize; i++) {
				q.push({i, 0});
				seen[i][0] = true;
			}
			for (int j = 0; j < ysize; j++) {
				q.push({0, j});
				seen[0][j] = true;
			}
		}

		while (!q.empty()) {
			p = q.front();
			q.pop();

			for (auto a : adjacent(p[0], p[1], matrix)) {
				// confusing, but water can only flow uphill in this case
				if ((!(seen[a[0]][a[1]])) &&
					matrix[a[0]][a[1]] >= matrix[p[0]][p[1]]) {
					seen[a[0]][a[1]] = true;
					q.push(a);
				}
			}
		}
		// build list of cells that can reach the given sea
		for (int i = 0; i < xsize; i++) {
			for (int j = 0; j < ysize; j++) {
				if (seen[i][j]) { r.push_back({i, j}); }
			}
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	// vector<vector<int>> matrix = {{1, 2, 2, 3, 5},
	//							  {3, 2, 3, 4, 4},
	//							  {2, 4, 5, 3, 1},
	//							  {6, 7, 1, 4, 5},
	//							  {5, 1, 1, 2, 4}};
	vector<vector<int>> matrix = {{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}};
	// vector<vector<int>> matrix = {{1, 1},{1, 1},{1, 1}};
	// cout << ((s.bfs_oceans(1, 4, matrix)) ? "true\n" : "false\n");
	s.pacificAtlantic(matrix);
	return 0;
}
