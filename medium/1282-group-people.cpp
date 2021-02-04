// 1282-group-people.cpp
// 2021-02-03

// There are n people that are split into some unknown number of groups. Each
// person is labeled with a unique ID from 0 to n - 1.

// You are given an integer array groupSizes, where groupSizes[i] is the size of
// the group that person i is in. For example, if groupSizes[1] = 3, then person
// 1 must be in a group of size 3.

// Return a list of groups such that each person i is in a group of size
// groupSizes[i].

// Each person should appear in exactly one group, and every person must be in a
// group. If there are multiple answers, return any of them. It is guaranteed
// that there will be at least one valid solution for the given input.

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes)
	{
		unordered_map<int, forward_list<int>> groups;
		vector<vector<int>> res;
		vector<int> allocation;

		for (int i = 0; i < (int)groupSizes.size(); i++) {
			// person id i is indexed by their desired group size
			groups[groupSizes[i]].push_back(i);
		}

		for (auto g : groups) {
			while (!g.second.empty()) {
				allocation = {};
				for (int i = 0; i < g.first; i++) {
					allocation.push_back(g.second.front());
					g.second.pop_front();
				}
				res.push_back(allocation);
			}
		}
		return res;
	}
};
