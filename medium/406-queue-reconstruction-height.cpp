// 406-queue-reconstruction-height.cpp
// 2021-01-15

// You are given an array of people, people, which are the attributes of some
// people in a queue (not necessarily in order). Each people[i] = [hi, ki]
// represents the ith person of height hi with exactly ki other people in front
// who have a height greater than or equal to hi.

// Reconstruct and return the queue that is represented by the input array
// people. The returned queue should be formatted as an array queue, where
// queue[j] = [hj, kj] is the attributes of the jth person in the queue
// (queue[0] is the person at the front of the queue).
// START: 12:52
// END: 13:41

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		vector<vector<int>> r;
		auto cmp = [&people](int a, int b) { return people[a][0] > people[b][0] ||
				(people[a][0] == people[b][0] && people[a][1] < people[b][1]); };
		vector<int> peeps(people.size(), 0);
		iota(peeps.begin(), peeps.end(), 0);
		sort(peeps.begin(), peeps.end(), cmp);

		for (int p : peeps) {
			r.insert(r.begin() + people[p][1], people[p]);
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
	vector<vector<int>> p2 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	auto op = s.reconstructQueue(p2);
	for (auto p : op) {
		cout << p[0] << "," << p[1] << endl;
	}
	return 0;
}
