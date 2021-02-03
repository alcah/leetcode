// Given the root of a binary tree, return the maximum path sum.

// For this problem, a path is defined as any node sequence from some starting
// node to any node in the tree along the parent-child connections. The path
// must contain at least one node and does not need to go through the root.

#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x), left(left), right(right) {}
};
class Solution {
public:
	int maxPathSum(TreeNode* root)
	{
		int max_path = INT_MIN;
		function<int(TreeNode*)> recur;

		// recursive function where we track the max in any branch as well as
		// the maximum path up through the root
		recur = [&](TreeNode* root) {
			if (root == NULL) { return 0; }
			int right = 0, left = 0, val = 0;
			right = recur(root->right);
			left = recur(root->left);
			val = max(root->val,
					  max(root->val + right, root->val + left));
			max_path = max(max_path, max(root->val + left + right, val));
			return val;
		};

		return max(max_path, recur(root));
	}
};

int main(int argc, char *argv[])
{
	TreeNode t(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	Solution s;
	cout << s.maxPathSum(&t) << endl;
	return 0;
}
