// 117-populating-next-right-pointers.cpp
// 2021-02-15

// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }

// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Follow up:

// You may only use constant extra space.  Recursive approach is fine, you may
// assume implicit stack space does not count as extra space for this problem.


#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root)
	{
		vector<Node*> last;
		f(root, 0, last);
		return root;
	}

	void f(Node* t, int depth, vector<Node*> &last)
	{
		if (t == NULL) { return; }

		if ((int)last.size() < depth) {
			t->next = NULL;
			last.push_back(t);
		} else {
			t->next = last[depth];
			last[depth] = t;
		}

		f(t->right, depth + 1, last);
		f(t->left, depth + 1, last);

		return;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
