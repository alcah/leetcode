#include <queue>


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        // pre-order tree traversal
        Node *p = head;
        while(p != NULL) {
            if (p->child) {
                p->next = flatten(append(p->next, p->child));
                p->child = NULL;
                return head;
            }
        }
        // if we reach here the list was already flat
        return head;
    }
    Node* append(Node *a, Node *b) {
        Node **p = &a;
        while ((*p) != NULL) {
            p = &((*p)->next);
        }
        (*p)->next = b;
        return a;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}
