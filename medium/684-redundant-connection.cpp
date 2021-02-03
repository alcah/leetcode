// 684-redundant-connection.cpp
// 2021-02-02
// TOPIC: Disjoint Set


// In this problem, a tree is an undirected graph that is connected and has no
// cycles.

// The given input is a graph that started as a tree with N nodes (with distinct
// values 1, 2, ..., N), with one additional edge added. The added edge has two
// different vertices chosen from 1 to N, and was not an edge that already
// existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is
// a pair [u, v] with u < v, that represents an undirected edge connecting nodes
// u and v.

// Return an edge that can be removed so that the resulting graph is a tree of N
// nodes. If there are multiple answers, return the answer that occurs last in
// the given 2D-array. The answer edge [u, v] should be in the same format, with
// u < v.

// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3

#include <bits/stdc++.h>
using namespace std;

class DS {
public:
	DS(int n) {
		v.resize(n);
		iota(v.begin(), v.end(), 0);
	}

	void unify(int a, int b) {
		v[find(a)] = find(b);
		return;
	}

	int find(int n) {
		if (v[n] != n) {
			v[n] = find(v[n]);
		}
		return v[n];
	}
private:
	vector<int> v;
};


class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges)
	{
		// there can be at most n vertices where n is the size of edges
		DS ds(edges.size());

		for (auto e : edges) {
			// if we try to union 2 edges that are already connected it must
			// create a cycle
			if (ds.find(e[0]) == ds.find(e[1])) { return e; }
			ds.unify(e[0], e[1]);
		}
		// this should never be reached
		return {0, 0};
	}

};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
