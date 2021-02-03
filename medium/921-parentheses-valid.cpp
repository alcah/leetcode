#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minAddToMakeValid(string S)
	{
		int depth = 0;
		int add = 0;
		for (char c : S) {
			if (c == '(') { depth++; }
			else if (c == ')') {
				depth--;
				if (depth < 0) {
					add++;
					depth = 0;
				}
			}
		}
		add += depth;
		return add;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.minAddToMakeValid("()))((") << endl;
	return 0;
}
