// 449-serialise-deserialise-bst.cpp
// 2021-01-27

// Serialization is converting a data structure or object into a sequence of
// bits so that it can be stored in a file or memory buffer, or transmitted
// across a network connection link to be reconstructed later in the same or
// another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There
// is no restriction on how your serialization/deserialization algorithm should
// work. You need to ensure that a binary search tree can be serialized to a
// string, and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


  // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string res;
		function<void(TreeNode*)> f;

		f = [&f,&res](TreeNode* t) {
			if (t == NULL) {
				res += "n ";
				return;
			}

			res += to_string(t->val) + " ";
			f(t->left);
			f(t->right);
		};
		f(root);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		stringstream ss(data);
		string item;
		queue<string> elems;
		while (getline(ss, item, ' ')) {
			elems.push(item);
		}
		function<TreeNode*()> f;
		f = [&f,&elems]() -> TreeNode* {
			string s;
			TreeNode *t;
			if (elems.empty()) { return NULL;}
			s = elems.front();
			elems.pop();
			if (s == "n") { return NULL; }
			t = new TreeNode(stoi(s));
			t->left = f();
			t->right = f();
			return t;
		};
		return f();
	}
};

int main(int argc, char *argv[])
{
	Codec s;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	string st = s.serialize(root);
	cout << st << endl;
	cout << s.serialize(s.deserialize(st)) << endl;
	return 0;
}
