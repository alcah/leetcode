// 1265-print-immutable-linked-list-in-reverse.cpp
// 2021-01-05

#include <bits/stdc++.h>

using namespace std;

class ImmutableListNode {
public:
	void printValue(); // print the value of the node.
	ImmutableListNode* getNext(); // return the next node.
};

class recursiveSolution {
public:
	void printLinkedListInReverse(ImmutableListNode* head)
	{
		if (head == nullptr) { return; }
		printLinkedListInReverse(head->getNext());
		head->printValue();
		return;
	}
};

class iterativeSolution {
public:
	void printLinkedListInReverse(ImmutableListNode* head)
	{
		stack<ImmutableListNode*> s;

		for (ImmutableListNode *n = head; n != nullptr; n = n->getNext()) {
			s.push(n);
		}

		while (!(s.empty())) {
			s.top()->printValue();
			s.pop();
		}

		return;
	}
};
