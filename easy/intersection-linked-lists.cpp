// intersection-linked-lists.cpp
// 2021-01-20

#include <bits/stdc++.h>

using namespace std;

// Write a program to find the node at which the intersection of two singly
// linked lists begins.

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		// traverse lists with 2 pointers, when pointer a reaches the end of A,
		// move it to headB.  If pointers are equal that is the point of intersection.
		// otherwise they'll be null at the same time.
		ListNode *pa = headA, *pb = headB;
		while (pa != pb) {
			pa = pa ? pa->next : headB;
			pb = pb ? pb->next : headA;
		}

		return pa;
	}
};
