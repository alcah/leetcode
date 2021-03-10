// 384-shuffle-array.cpp
// 2021-02-17
// LEARNT: Fisher-Yates Algorithm -- or what it's called

// Given an integer array nums, design an algorithm to randomly shuffle the
// array.

// Implement the Solution class:

// Solution(int[] nums) Initializes the object with the integer array nums.
// int[] reset() Resets the array to its original configuration and returns it.
// int[] shuffle() Returns a random shuffling of the array.

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(vector<int>& nums) {
		arr = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return arr;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> copy = arr;
		int n = arr.size();
		for (int i = 0; i < (int)copy.size(); i++) {
			swap(copy[i], copy[rand() % n]);
		}
		return copy;
	}

private:
	vector<int> arr;
};
