// 538-convert-bst-greater-tree.cpp
// 2021-01-20

#include <bits/stdc++.h>

using namespace std;

// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
// such that every key of the original BST is changed to the original key plus
// sum of all keys greater than the original key in BST.

// As a reminder, a binary search tree is a tree that satisfies these
// constraints:

// The left subtree of a node contains only nodes with keys less than the node's
// key.  The right subtree of a node contains only nodes with keys greater than
// the node's key.  Both the left and right subtrees must also be binary search
// trees.  Note: This question is the same as 1038:
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

  // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int sum = 0;
	TreeNode* bstToGst(TreeNode* root)
	{
		// greatest to smallest traversal of tree; keeping track of running sum
		if (root->right) { bstToGst(root->right); }
		sum = root->val = root->val + sum;
		if (root->left) { bstToGst(root->left); }
		return root;
	}
};
