// 382-linked-list-random-node.cpp
// 2021-01-30
// TOPIC: Sampling
// LEANT: Reservoir Sampling

// Given a singly linked list, return a random node's value from the linked
// list. Each node must have the same probability of being chosen.

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
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
	/** @param head The linked list's head.  Note that the head is guaranteed to
		be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		list = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		// maximum of O(2n) iterations if n = 2n-1, usually much less
		int mod = (length ? length : pow(10, 4));
		int n = rand() % mod;
		ListNode *p = list;

		for (int i = n; i > 0; i--) {
			if (p == NULL) {
				this->length = n - i;
				p = list->next;
				i %= length;
			}
			else {
				p = p->next;
			}
		}
		return (p ? p->val : list->val);
	}
	ListNode* list;
	int length = 0;
};

// Reservoir sampling
class Solution {
public:
	/** @param head The linked list's head.  Note that the head is guaranteed to
		be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		list = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int reservoir = 0;
		int range = 1;
		ListNode *p = list;
		while (p != NULL) {
			if (rand() % range == 0) {
				reservoir = p->val;
			}
			range++;
			p = p->next;
		}
		return reservoir;
	}
	ListNode* list;
};
