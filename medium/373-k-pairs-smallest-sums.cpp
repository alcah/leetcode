// 373-k-pairs-smallest-sums.cpp
// 2021-02-15

// You are given two integer arrays nums1 and nums2 sorted in ascending order
// and an integer k.

// Define a pair (u,v) which consists of one element from the first array and
// one element from the second array.

// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		auto f = [&nums1, &nums2](pair<int,int> &a, pair<int,int> &b) {
			return (nums1[a.first] + nums2[a.second]) >
				(nums1[b.first] + nums2[b.second]);
		};
		vector<vector<int>> res;
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(f)> q(f);
		// essentially a bfs so we record if we've seen each pair
		vector<vector<bool>> seen(nums1.size(), vector<bool>(nums2.size(), false));

		if (nums1.empty() || nums2.empty()) { return res; }

		q.push({0, 0});
		seen[0][0] = true;

		for (int i = 0, j = 0; !q.empty() && k > 0; q.pop(), k--) {
			i = q.top().first;
			j = q.top().second;
			// take current value
			res.push_back({nums1[i], nums2[j]});

			// push next possible values
			if (i + 1 < (int)nums1.size() && !seen[i+1][j]) {
				q.push({i+1, j});
				seen[i+1][j] = true;
			}
			if (j + 1 < (int)nums2.size() && !seen[i][j+1]) {
				q.push({i, j+1});
				seen[i][j+1] = true;
			}
		}

		return res;
	}
};
