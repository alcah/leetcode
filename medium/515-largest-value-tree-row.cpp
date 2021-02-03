// 515-largest-value-tree-row.cpp
// 2021-01-28
// START: 20:27:19
// END: 20:34:50

// Given the root of a binary tree, return an array of the largest value in each
// row of the tree (0-indexed).

// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]

// Constraints:
// The number of nodes in the tree will be in the range [0, 104].
// -231 <= Node.val <= 231 - 1

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> largestValues(TreeNode* root)
	{
		f(root, 0);
		return largest;
	}

	void f(TreeNode* t, int rank)
	{
		if (t == NULL) { return; }
		if (largest.size() <= rank) { largest.push_back(t->val); }
		largest[rank] = max(largest[rank], t->val);
		f(t->left, rank + 1);
		f(t->right, rank + 1);
		return;
	}
	vector<int> largest;
};
