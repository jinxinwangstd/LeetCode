/*
class Node {
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

class Solution {
public:
    pair<Node*, Node*> flattenHelper(Node *head) {
        Node *cur = head;
        while (cur->next) {
            if (cur->child) {
                Node *next_head = cur->next;
                pair<Node*, Node*> child = flattenHelper(cur->child);
                cur->child = NULL;
                cur->next = child.first;
                child.first->prev = cur;
                child.second->next = next_head;
                next_head->prev = child.second;
                cur = next_head;
            }
            else
                cur = cur->next;
        }
        if (cur->child) {
            pair<Node*, Node*> child = flattenHelper(cur->child);
            cur->child = NULL;
            cur->next = child.first;
            child.first->prev = cur;
            return make_pair(head, child.second);
        }
        else
            return make_pair(head, cur);
    }
    Node* flatten(Node *head) {
        if (head)
            flattenHelper(head);
        return head;
    }
};
