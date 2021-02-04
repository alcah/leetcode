// 23-merge-k-sorted-lists.cpp
// 2021-02-04
// START: 23:40:00
// END: 00:45:00
// O(n*log(k))

// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// * Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode *head;
		ListNode **p = &head;
		auto f = [](ListNode* p, ListNode* q){ return p->val > q->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(f)> q(f);

		for (ListNode* n : lists) {
			if (n) { q.push(n); }
		}

		for (; !q.empty(); q.pop()) {
			(*p) = q.top();
			if ((*p)->next != NULL) { q.push((*p)->next); }
			(*p)->next = NULL;
			p = &((*p)->next);
		}

		return head;

	}
};
