// 21-merge-sorted-lists.cpp
// 2021-01-20

// Merge two sorted linked lists and return it as a sorted list. The list should
// be made by splicing together the nodes of the first two lists.

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

// in-place iterative
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
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

// in-place recursive solution
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL && l2 == NULL) { return NULL; }
		if (l1 == NULL) { return l2; }
		if (l2 == NULL) { return l1; }

		// at this point both lists must be valid
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
