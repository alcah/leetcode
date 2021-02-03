// 322-coin-change.cpp
// 2021-01-10

// You are given coins of different denominations and a total amount of money
// amount. Write a function to compute the fewest number of coins that you need
// to make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
// START: 13:26:30
// END: 16;15;00


	// // really just the same as above, but we guarantee the input is sorted
	// // This greedy approach doesn't work; consider (7, {1,3,4,5})
	// int coinChanger(vector<int>& coins, int amount) {
	//	// this is a classic dynamic programming problem
	//	// I don't actually know the DP solution, only the recursive one
	//	if (amount < 0 || coins.size() < 1) { return -1; }
	//	if (amount == 0) { return 0; }
	//	runcount += 1;
	//	cout << "run " << runcount << ": " << amount << endl;
	//	int ncoins = 0;
	//	vector<int> subcoins;
	//	// use largest denomination to reduce amount.
	//	if ((ncoins = coinChanger(coins, amount-coins[coins.size()-1])) >= 0) {
	//		return ncoins + 1;
	//	}

	//	// new vector with all coins except the largest denomination
	//	copy(coins.begin(), coins.end()-1, back_inserter(subcoins));
	//	return ncoins = coinChanger(subcoins, amount);
	// }



#include <bits/stdc++.h>

using namespace std;

// top down dynamic programming approach
// class Solution {
// public:
//	int coinChange(vector<int>& coins, int amount)
//	{
//		if (amount < 0) { return -1; }
//		if (amount == 0) { return 0; }
//		if (dp[amount] != 0) { return dp[amount]; }

//		int sub = 0;
//		int min = INT_MAX;

//		// get the minimum of making change from amount minus each of the coins
//		for (int c : coins) {
//			sub = coinChange(coins, amount - c);
//			if (sub >= 0 && sub < min) { min = sub + 1; }
//		}

//		dp[amount] = (min == INT_MAX) ? -1 : min;
//		return dp[amount];
//	}

// private:
//	unordered_map<int, int> dp;
// };

// bottom up dynamic programming
class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		// move through range finding fewest coins for each number
		vector<int> dp(amount+1, amount+1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < (int)coins.size(); j++) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i-coins[j]] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}

private:
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<int> coins1 = {1,2,5};
	vector<int> coins2 = {2};
	vector<int> coins3 = {2, 5, 10, 1};
	vector<int> coins4 = {186, 419, 83, 408};
	cout << s.coinChange(coins1, 11) << endl;
	cout << s.coinChange(coins2, 3) << endl;
	cout << s.coinChange(coins3, 27) << endl;
	cout << s.coinChange(coins4, 6249) << endl;
	return 0;
}
