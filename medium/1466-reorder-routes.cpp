// 1466-reorder-routes.cpp
// 2021-01-24

#include <bits/stdc++.h>

using namespace std;

// There are n cities numbered from 0 to n-1 and n-1 roads such that there is
// only one way to travel between two different cities (this network form a
// tree). Last year, The ministry of transport decided to orient the roads in
// one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [a, b] represents
// a road from city a to b.

// This year, there will be a big event in the capital (city 0), and many people
// want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit
// the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach the city 0 after reorder.

// edgelist
typedef vector<forward_list<int>> el;

class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections)
	{
		el outgoing(n);
		el incoming(n);

		// initialise graph
		for (auto c : connections) {
			outgoing[c[0]].push_front(c[1]);
			incoming[c[1]].push_front(c[0]);
		}

		// search out from the capital
		return makeIncoming(0, -1, outgoing, incoming);
;
	}

	// dfs from node START counting OUTGOING edges.
	// BREADCRUMB leads back to the capital; don't follow
	// works because the graph is directed
	int makeIncoming(int start, int breadcrumb, el &outgoing, el &incoming)
	{
		int count = 0;
		for (int e : outgoing[start]) {
			if (e != breadcrumb) {
				count += makeIncoming(e, start, outgoing, incoming);
				count++;
			}
		}
		for (int e : incoming[start]) {
			if (e != breadcrumb) {
				count += makeIncoming(e, start, outgoing, incoming);
			}
		}
		return count;
	}
};
