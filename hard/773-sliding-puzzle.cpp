// 773-sliding-puzzle.cpp
// 2021-02-02

// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
// and an empty square represented by 0.

// A move consists of choosing 0 and a 4-directionally adjacent number and
// swapping it.

// The state of the board is solved if and only if the board is
// [[1,2,3],[4,5,0]].

// Given a puzzle board, return the least number of moves required so that the
// state of the board is solved. If it is impossible for the state of the board
// to be solved, return -1.

// Examples:

// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> brd;

class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& board)
	{
		return f(board);
	}

	pair<int, int> zero(brd &board)
	{
		pair<int,int> zero;

		for (int i = 0; i < (int)board.size(); ++i) {
			for (int j = 0; j < (int)board[0].size(); ++j) {
				if (board[i][j] == 0) { zero = {i, j}; }
			}
		}
		return zero;
	}

	int intify(brd &board)
	{
		int p = 1;
		int res = 0;
		for (auto v : board) {
			for (int i : v) {
				res += i*p;
				p *= 10;
			}
		}
		return res;
	}

	// BFS where we don't retread board states
	int f(brd board)
	{
		const vector<pair<int,int>> adj =
			{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		const int m = board.size();
		const int n = board[0].size();
		unordered_map<int, bool> seen;
		int y = 0, x = 0;
		int boardint = intify(board);
		int depth;
		pair<int,int> z;

		queue<pair<int, brd>> q;
		q.push({0, board});
		seen[boardint] = true;

		for (; !q.empty(); q.pop()) {
			depth = q.front().first;
			board = q.front().second;
			z = zero(board);
			boardint = intify(board);
			if (boardint == 123450) { return depth; }
			for (auto a : adj) {
				y = z.first + a.first;
				x = z.second + a.second;

				if (y >= m || y < 0 ||
					x >= n || x < 0) {
					continue;
				}

				swap(board[z.first][z.second], board[y][x]);

				if (seen[boardint]) {
					swap(board[z.first][z.second], board[y][x]);
					continue;
				}

				q.push({depth+1, board});
				seen[boardint] = true;
				swap(board[z.first][z.second], board[y][x]);
			}
		}
		return -1;
	}
};
