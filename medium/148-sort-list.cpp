// 148-sort-list.cpp
// 2021-01-25

// Given the head of a linked list, return the list after sorting it in
// ascending order.

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
// (i.e. constant space)?

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

// mergesort
class Solution {
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL || head->next == NULL) { return head; }
		ListNode **p = midpoint(head);
		ListNode *q = *p;
		*p = NULL;
		return merge(sortList(head), sortList(q));
	}

	// return pointer to next pointing to middle node
	ListNode** midpoint(ListNode* head)
	{
		ListNode *p = head;
		ListNode **q = &head;

		while (p != NULL) {
			q = &((*q)->next);
			p = p->next;
			if (p != NULL) { p = p->next; }
		}
		return q;
	}

	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode *res = NULL;
		// p points to the pointer to the next node
		ListNode **n = &res;
		ListNode **p = &l1;

		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) {
				*n = l2;
				break;
			}
			else if (l2 == NULL) {
				*n = l1;
				break;
			}
			p = (l1->val < l2->val) ? &l1 : &l2;

			*n = *p;
			*p = (*p)->next;
			n = &((*n)->next);
			*n = NULL;

		}
		return res;
	}
};

void printll(ListNode* ll)
{
	for (ListNode *p = ll; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
}

int main(int argc, char *argv[])
{
	ListNode *ll = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
	Solution s;
	ll = s.sortList(ll);
	printll(ll);
	cout << endl;
	return 0;
}
