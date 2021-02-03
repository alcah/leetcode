// random-flip-matrix.cpp
// 2021-01-24

// You are given the number of rows n_rows and number of columns n_cols of a 2D
// binary matrix where all values are initially 0. Write a function flip which
// chooses a 0 value uniformly at random, changes it to 1, and then returns the
// position [row.id, col.id] of that value. Also, write a function reset which
// sets all values back to 0. Try to minimize the number of calls to system's
// Math.random() and optimize the time and space complexity.

// Note:
// 1 <= n_rows, n_cols <= 10000
// 0 <= row.id < n_rows and 0 <= col.id < n_cols
// flip will not be called when the matrix has no 0 values left.
// the total number of calls to flip and reset will not exceed 1000.


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	Solution(int n_rows, int n_cols)
	{
		ncols = n_cols;
		nrows = n_rows;
		return;
	}

	// return position of flipped value must choose 0 zero uniformly at
	// random. i.e. ignore already set values
	vector<int> flip()
	{
		if ((int)flipped.size() == ncols*nrows) { return {}; }
		int i = rand() % (ncols*nrows);
		while (flipped.count(i)) {
			++i;
			i = i % (ncols*nrows);
		}

		flipped.insert(i);

		return {i / ncols, i % ncols};
	}

	// a naive reset will be in linear time instead we'll record a list of that
	// have been flipped and unflip them.  linear time in number of flipped bits
	void reset()
	{
		flipped = {};
		return;
	}
private:
	int ncols;
	int nrows;
	// list of flipped indices
	unordered_set<int> flipped;
};

int main(int argc, char *argv[])
{
	Solution s(5, 5);
	s.flip();
	s.flip();
	s.reset();
	return 0;
}
