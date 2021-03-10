// 889-binary-tree-inorder-postorder.cpp
// 2021-03-10


// Return any binary tree that matches the given preorder and postorder
// traversals.

// Values in the traversals pre and post are distinct positive integers.



// Example 1:

// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1] Output: [1,2,3,4,5,6,7]


// Note:

// 1 <= pre.length == post.length <= 30 pre[] and post[] are both permutations
// of 1, 2, ..., pre.length.  It is guaranteed an answer exists. If there exists
// multiple answers, you can return any of them.

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
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		int p = 0, q = 0;
		return reconstruct(pre, post, p, q);
	}

	TreeNode* reconstruct(vector<int> &pre, vector<int> &post, int &p, int &q)
	{
		TreeNode *res = new TreeNode(pre[p++]);
		if (post[q] == res->val) {
			q++;
			return res;
		}

		// there must be a left subtree
		res->left = reconstruct(pre, post, p, q);
		if (post[q] == res->val) {
			q++;
			return res;
		}

		// there must be a right subtree
		res->right = reconstruct(pre, post, p, q);
		q++;
		return res;
	}
};
