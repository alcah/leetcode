// 605-can-place-flower.cpp
// 2021-02-22

// You have a long flowerbed in which some of the plots are planted, and some
// are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty
// and 1 means not empty, and an integer n, return if n new flowers can be
// planted in the flowerbed without violating the no-adjacent-flowers rule.

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		const int fbsize = flowerbed.size();
		// my intuition says use a greedy search -- will that work?
		// I can't think of any counter examples
		for (int i = 0; i < (int)flowerbed.size() && n > 0; ++i) {
			if (flowerbed[i] == 0
				&& (i+1 >= fbsize || flowerbed[i+1] == 0)
				&& (i-1 < 0 || flowerbed[i-1] == 0)) {
				n--;
				i++;
			}
			else if (flowerbed[i] == 1) { i++; }
		}
		return (n > 0 ? false : true);
	}
};
