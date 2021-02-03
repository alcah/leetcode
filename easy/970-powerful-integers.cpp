#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
	static vector<int> powerfulIntegers(int x, int y, int bound) {
		set<int> powerful;

		for (int m = 1; m < bound; m *= x) {
			for (int n = 1; m + n <= bound; n *= y) {
				powerful.insert(m + n);
				if (y == 1) { break; }
			}
			if (x == 1) { break; }
		}

		return vector<int>(powerful.begin(), powerful.end());
	}
};

int main(int argc, char *argv[])
{
	vector<int> p = Solution::powerfulIntegers(2, 1, 10);
	for (int i : p) {
		cout << i << endl;
	}

	return 0;
}
