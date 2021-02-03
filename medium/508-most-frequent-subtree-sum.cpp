#include <bits/stdc++.h>

using namespace std;

// Given the root of a tree, you are asked to find the most frequent subtree
// sum. The subtree sum of a node is defined as the sum of all the node values
// formed by the subtree rooted at that node (including the node itself). So
// what is the most frequent subtree sum value? If there is a tie, return all
// the values with the highest frequency in any order.

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
	vector<int> findFrequentTreeSum(TreeNode* root)
	{
		function<int(TreeNode*)> recur;
		unordered_map<int, int> freq;
		int max = INT_MIN;
		vector<int> r;

		recur = [&recur, &freq](TreeNode *root)
		{
			// base case
			if (!root) { return 0; }
			int r = recur(root->left) +
				root->val +
				recur(root->right);
			freq[r]++;
			return r;
		};
		recur(root);

		for (auto a : freq) {
			max = (a.second > max) ? a.second : max;
		}

		for (auto a : freq) {
			if (a.second == max) { r.push_back(a.first); }
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	TreeNode root;
	TreeNode left;
	TreeNode right;
	root.val = 5;
	root.left = &left;
	left.val = 2;
	root.right = &right;
	right.val = -5;
	for (auto e : s.findFrequentTreeSum(&root)) {
		cout << e << endl;
	}
	return 0;
}
