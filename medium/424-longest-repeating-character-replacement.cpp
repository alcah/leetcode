// 424-longest-repeating-character-replacement.cpp
// 2021-01-30
// START: 22:34:16

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k)
	{
		vector<int> freq(26, 0);
		char maxfreq = 'A';
		int maxlength = 0;
		int spent = 0;

		for (int hi = 0, lo = 0; hi < (int)s.size(); hi++) {
			// increment char freq
			if (++(freq[s[hi] - 'A']) > freq[maxfreq - 'A']) {
				maxfreq = s[hi];
			}
			spent = (hi - lo + 1) - freq[maxfreq - 'A'];

			if (spent > k) { freq[s[lo++] - 'A']--; }
			maxlength = max((hi - lo + 1), maxlength);
		}

		return maxlength;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.characterReplacement("ABABBB", 1) << endl;
	return 0;
}
