// 959-regions-cut-slashes.cpp
// 2021-01-18

// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /,
// \, or blank space.  These characters divide the square into contiguous
// regions.

// (Note that backslash characters are escaped, so a \ is represented as "\\".)

// Return the number of regions.


#include <bits/stdc++.h>

using namespace std;

#define MAX_EDGES 1000

int rmaref(int y, int x, int size) {
	return y *size +x;
}

struct edge {
	int y;
	edge *next;
};


class graph {
public:
	int degree[MAX_EDGES] = {0};
	int nvertices = 0;
	int nedges = 0;
	graph(int n) {
		for (int i = 0; i < n; i++)
			{
				insert_edge(rmaref(0, i, n), rmaref(0, i+1, n));
				insert_edge(rmaref(i, 0, n), rmaref(i+1, 0, n));
				insert_edge(rmaref(n, i, n), rmaref(n, i+1, n));
				insert_edge(rmaref(i, n, n), rmaref(i+1, n, n));
			}
	};
	void insert_edge(int a, int b) {
		nedges++;
		if (++degree[a] == 1) { nvertices++; };
		if (++degree[b] == 1) { nvertices++; };
	}
};

class Solution {
public:
	int regionsBySlashes(vector<string>& grid)
	{
		int n = grid.size();
		graph g(n);

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				switch(grid[y][x]) {
				case ' ':
					break;
				case '/':
					g.insert_edge(rmaref(y, x+1, n), rmaref(y+1, x, n));
					break;
				case '\\':
					g.insert_edge(rmaref(y, x, n), rmaref(y+1, x+1, n));
					break;
				}
			}
		}
		return ((g.nedges + 2) - g.nvertices) - 1;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
