// 1496-path-crossing.cpp
// 2021-02-04
// START 23:17:20
// END 23:31:30
// LEARNT: no way to hash a pair

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isPathCrossing(string path)
	{
		set<pair<int,int>> s;
		int y = 0;
		int x = 0;

		s.insert({y, x});

		for (char c : path) {
			if (c == 'N') { y--; }
			else if (c == 'S') { y++; }
			else if (c == 'E') { x--; }
			else { x++; }
			if (s.count({y, x})) { return true; }
			s.insert({y, x});
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isPathCrossing("NWSNWE") << endl;
	return 0;
}
