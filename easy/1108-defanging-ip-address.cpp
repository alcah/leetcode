#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string defangIPaddr(string address)
	{
		string res;
		for (auto c : address) {
			if (c == '.') { res.append("[.]"); }
			else { res.push_back(c); }
		}
		return res;
	}
};
