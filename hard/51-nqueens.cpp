// 51-nqueens.cpp
// 2021-01-25

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n)
	{
		string s(n, '.');
		vector<vector<string>> r;
		f(n, {});

		for (vector<int> solution : solutions) {
			vector<string> vs = {};
			for (int p : solution) {
				s[p] = 'Q';
				vs.push_back(s);
				s[p] = '.';
			}
			r.push_back(vs);
		}
		return r;
	}

	void f(int n, vector<int> placed)
	{
		if ((int)placed.size() == n) { solutions.push_back(placed); }

		// for each potential next position
		for (int p = 0; p < n; p++) {
			if (canPlace(p, placed)) {
				placed.push_back(p);
				f(n, placed);
				placed.pop_back();
			}
		}
		return;
	}

	bool canPlace(int p, vector<int> &placed)
	{
		for (int q = 0; q < (int)placed.size(); q++) {
			// diagonals = q +- |Colq - Colp|
			if (placed[q] == p ||
				p == placed[q] + abs((int)placed.size() - q) ||
				p == placed[q] - abs((int)placed.size() - q))
				{ return false; }
		}
		return true;
	}
private:
	vector<vector<int>> solutions;
};

void printBoard(vector<string> board) {
	cout << "---------------" << endl;
	for (auto s : board) {
		cout << s << endl;
	}
}

int main(int argc, char *argv[])
{
	int n = 4;
	Solution s;

	if (argc > 1) { n = stoi(argv[1]); }
	auto boards = s.solveNQueens(n);
	for (auto b : boards) { printBoard(b); }
	return 0;
}
