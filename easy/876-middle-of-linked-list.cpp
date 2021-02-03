#include <bits/stdc++.h>

using namespace std;

  // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head)
	{
		int length = 0;
		for (ListNode *n = head; n != NULL; n = n->next)
		{
			length++;
		}
		for (length = (length) / 2; length > 0; length--)
		{
			head = head->next;
		}
			 return head;
	}
};
