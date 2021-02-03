// 870-advantage-shuffle.cpp
// 2021-01-22

// Given two arrays A and B of equal size, the advantage of A with respect to B
// is the number of indices i for which A[i] > B[i].

// Return any permutation of A that maximizes its advantage with respect to B.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B)
	{
		vector<int> r(B.size());
		unordered_map<int, list<int>> assigned;
		stack<int> remaining;
		vector<int> sortedA = A;
		vector<int> sortedB = B;
		int j = 0;

		sort(sortedA.begin(), sortedA.end());
		sort(sortedB.begin(), sortedB.end());

		assigned[0].empty();

		for (auto a : sortedA) {
			if (a > sortedB[j]) { assigned[sortedB[j++]].push_front(a); }
			else { remaining.push(a); }
		}

		// construct answer
		for (int i = 0; i < (int)r.size(); i++) {
			if (assigned.find(B[i]) != assigned.end() &&
				!(assigned[B[i]].empty())) {
				r[i] = assigned[B[i]].front();
				assigned[B[i]].pop_front();
			}
			else {
				r[i] = remaining.top();
				remaining.pop();
			}
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
