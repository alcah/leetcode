#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int kthGrammar(int N, int K)
	{
		string current = "0";
		string next = "";

		for (int i = 1; i < N; i++) {
			for (char c : current) {
				if (c == '0') { next += "01"; }
				else { next += "10"; }
			}
			current = next;
			next = "";
		}

		return current[K-1] - '0';
	}
};

int main(int argc, char *argv[])
{

	return 0;
}

/*
N = 3
  1
  2
  3
 */
