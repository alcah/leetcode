// 587-erect-the-fence.cpp
// 2021-02-07

// There are some trees, where each tree is represented by (x,y) coordinate in a
// two-dimensional garden. Your job is to fence the entire garden using the
// minimum length of rope as it is expensive. The garden is well fenced only if
// all the trees are enclosed. Your task is to help find the coordinates of
// trees which are exactly located on the fence perimeter.

#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
	vector<vector<int>> outerTrees(vector<vector<int>>& points)
	{
		int n = points.size();
		vector<vector<int>> stack;
		int ymin = 0;
		int idx = 0;
		vector<int> pn;
		// Graham Scan doesn't work with less than 3 points, but obviously all
		// must be included.
		if (n < 3) { return points; }

		// find lowest point in space
		for (int i = 1; i < n; i++) {
			if ((points[i][1] < points[ymin][1]) ||
				(points[i][1] == points[ymin][1] && points[i][0] < points[ymin][0])) {
				ymin = i;
			}
		}
		// swap ymin into first position
		swap(points[ymin], points[0]);

		// sort points by polar angle with ymin
		sort(points.begin(), points.end(), pointsComparator(points[0]));

		pn = points.back();
		if (orientation(points[0], points[1], pn) != 0) {
			idx = n-1;
			while (orientation(points[0], points[idx], pn) == 0) {
				idx--;
			}
			reverse(points.begin() + idx + 1, points.end());
		}

		// add first 3 vertices to stack
		stack.push_back(points[0]);
		stack.push_back(points[1]);
		stack.push_back(points[2]);

		for (int i = 3; i < n; i++) {
			// keep removing points from the stack until two top points and i
			// make a left hand turn
			while (orientation(stack[stack.size()-2], stack.back(), points[i]) >= 1) {
				stack.pop_back();
			}
			stack.push_back(points[i]);
		}
		return stack;
	}

private:
	// return squared distance between a and b
	static int distSq(const vector<int> &a, const vector<int> &b)
	{
		return (abs(a[0] - b[0]) << 1) + (abs(a[1] - b[1]) << 1);
	}

	// return the magnitude (z-component) of the cross product of the given
	// vectors lying on the z plane
	// positive: clockwise
	// negative: anticlockwise
	// zero: colinear
	static int orientation(const vector<int> &p, const vector<int> &q, const vector<int> &r)
	{
		return ((q[1]-p[1]) * (r[0] - q[0])) - ((q[0] - p[0]) * (r[1] - q[1]));
	}


	// compare points
	struct pointsComparator {
		vector<int> p;
		pointsComparator(const vector<int> &point) : p(point) {}
		bool operator() (const vector<int> &a, const vector <int> &b)
		{
			int o = orientation(p, a, b);
			if (o == 0) { return distSq(p, b) >= distSq(p, a); }
			return o < 0;
		}

	};
};
