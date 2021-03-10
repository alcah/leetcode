// 145-binary-tree-postorder-traversal.cpp
// 2021-03-03

// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.

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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		vector<int> tmp;
		if (root == NULL) { return {}; }
		tmp = postorderTraversal(root->left);
		res.insert(res.end(), tmp.begin(), tmp.end());
		tmp = postorderTraversal(root->right);
		res.insert(res.end(), tmp.begin(), tmp.end());
		res.push_back(root->val);
		return res;
	}
};
