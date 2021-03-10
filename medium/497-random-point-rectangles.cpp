// 497-random-point-rectangles.cpp
// 2021-02-28

// Given a list of non-overlapping axis-aligned rectangles rects, write a
// function pick which randomly and uniformily picks an integer point in the
// space covered by the rectangles.

// Note:

// An integer point is a point that has integer coordinates.  A point on the
// perimeter of a rectangle is included in the space covered by the rectangles.
// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer
// coordinates of the bottom-left corner, and [x2, y2] are the integer
// coordinates of the top-right corner.  length and width of each rectangle does
// not exceed 2000.  1 <= rects.length <= 100 pick return a point as an array of
// integer coordinates [p_x, p_y] pick is called at most 10000 times.  Example
// 1:

// Input: ["Solution","pick","pick","pick"] [[[[1,1,5,5]]],[],[],[]] Output:
// [null,[4,1],[4,1],[3,3]] Example 2:

// Input: ["Solution","pick","pick","pick","pick","pick"]
// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]] Output:
// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]] Explanation of Input Syntax:

// The input is two lists: the subroutines called and their
// arguments. Solution's constructor has one argument, the array of rectangles
// rects. pick has no arguments. Arguments are always wrapped with a list, even
// if there aren't any.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(vector<vector<int>>& rects) {
		rect = rects;
		totalrange = 0;
		int h = 0, w = 0;
		for (auto r : rects) {
			h = abs(r[3] - r[1]) + 1;
			w = abs(r[2] - r[0]) + 1;
			totalrange += h * w;
		}
		return;
	}

	vector<int> pick() {
		int n = rand() % totalrange;
		int h = 0, w = 0;
		vector<int> res = {0, 0};

		for (auto r : rect) {
			h = abs(r[3] - r[1]) + 1;
			w = abs(r[2] - r[0]) + 1;
			if (n < h * w) {
				res[1] = r[1] + (n / w);
				res[0] = r[0] + (n % w);
				break;
			}
			else {
				n -= h * w;
			}
		}
		return res;
	}
private:
	int totalrange;
	vector<vector<int>> rect;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
