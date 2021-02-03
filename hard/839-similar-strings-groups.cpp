// 839-similar-strings-groups.cpp
// 2021-01-09

// Two strings X and Y are similar if we can swap two letters (in different
// positions) of X, so that it equals Y. Also two strings X and Y are similar if
// they are equal.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
// and "rats" and "arts" are similar, but "star" is not similar to "tars",
// "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats",
// "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group
// even though they are not similar.  Formally, each group is such that a word
// is in the group if and only if it is similar to at least one other word in
// the group.

// We are given a list strs of strings where every string in strs is an anagram
// of every other string in strs. How many groups are there?
// START:

#include <bits/stdc++.h>

using namespace std;
class disjoint_set {
	vector<int> v;
	int sz;
public:
	disjoint_set(int n) {
		makeset(n);
	}

	void makeset(int n) {
		v.resize(n);
		iota(v.begin(), v.end(), 0);
		sz = n;
	}

	int find(int i) {
		if (i != v[i])
			v[i] = find(v[i]);
		return v[i];
	}

	void join(int i, int j) {
		int ri = find(i), rj = find(j);
		if (ri != rj) {
			v[ri] = rj;
			sz--;
		}
	}

	int size() {
		return sz;
	}
};


class Solution {
public:
	int numSimilarGroups(vector<string>& strs)
	{
		disjoint_set groups(strs.size());

		for (int i = 0; i < (int)strs.size(); i++) {
			for (int j = i+1; j < (int)strs.size(); j++) {
				if (groups.find(i) != groups.find(j) &&
					simmilar(strs[i], strs[j])) {
					groups.join(i, j);
				}
			}
		}

		return groups.size();
	}

	bool simmilar(string &a, string &b)
	{
		int error = 0;
		for (int i = 0; i < (int)a.size(); ++i) {
			if (a[i] != b[i] && ++error > 2) { return false; }
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> strs = {"tars","rats","arts","star"};
	cout << s.numSimilarGroups(strs) << endl;
	return 0;
}
