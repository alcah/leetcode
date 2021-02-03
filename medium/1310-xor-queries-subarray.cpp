// 1310-xor-queries-subarray.cpp
// 2021-01-27
// START: 21:48:45
// END: 22:33:45
// LEARNT: prefix sum, a ^ b ^ a = b property of xor

// Given the array arr of positive integers and the array queries where
// queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li
// to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array
// containing the result for the given queries.

// Example 1:

// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// Output: [2,7,14,8]
// Explanation:
// The binary representation of the elements in the array are:
// 1 = 0001
// 3 = 0011
// 4 = 0100
// 8 = 1000
// The XOR values for queries are:
// [0,1] = 1 xor 3 = 2
// [1,2] = 3 xor 4 = 7
// [0,3] = 1 xor 3 xor 4 xor 8 = 14
// [3,3] = 8


// 1 <= arr.length <= 3 * 10^4
// 1 <= arr[i] <= 10^9
// 1 <= queries.length <= 3 * 10^4
// queries[i].length == 2
// 0 <= queries[i][0] <= queries[i][1] < arr.length

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
	{
		vector<int> ps(arr.size());
		vector<int> res(queries.size());
		// initialise prefix xor
		ps[0] = arr[0];
		for (int i = 1; i < (int)arr.size(); ++i)
			{ ps[i] = ps[i-1] ^ arr[i]; }

		// query(x, y) = ps[y] ^ ps[x-1]
		// x ^ y ^ x = y for any x and y
		for (int i = 0; i < (int)queries.size(); i++) {
			res[i] = ps[queries[i][1]] ^
				(queries[i][0] == 0 ? 0 : ps[queries[i][0]-1]);
		}
		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> arr = {1, 3, 4, 8};
	vector<vector<int>> q = {{0,1},{1,2},{0,3},{3,3}};
	for (auto i : s.xorQueries(arr, q)) { cout << i << endl; }
	return 0;
}
