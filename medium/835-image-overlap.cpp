// 835-image-overlap.cpp
// 2021-02-04

// You are given two images img1 and img2 both of size n x n, represented as
// binary, square matrices of the same size. (A binary matrix has only 0s and 1s
// as values.)

// We translate one image however we choose (sliding it left, right, up, or down
// any number of units), and place it on top of the other image.  After, the
// overlap of this translation is the number of positions that have a 1 in both
// images.

// (Note also that a translation does not include any kind of rotation.)

// What is the largest possible overlap?

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> int2d;

class Solution {
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
	{
		int n = img1.size();
		int most = 0;
		int2d padded(3 * n - 2, vector<int>(3 * n - 2));

		// set up padded vector
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				padded[i + n - 1][j + n - 1] = img2[i][j];
			}
		}

		for (int xshift = 0; xshift < 2 * n - 1; ++xshift) {
			for (int yshift = 0; yshift < 2 * n - 1; ++yshift) {
				most = max(most, convolute(img1, padded, xshift, yshift));
			}
		}
		return most;
	}

	int convolute(const int2d &img, const int2d &kernel, int xshift, int yshift)
	{
		int res = 0;
		for (int i = 0; i < (int)img.size(); i++) {
			for (int j = 0; j < (int)img.size(); j++) {
				res += img[i][j] * kernel[i+yshift][j+xshift];
			}
		}
		return res;
	}
};
