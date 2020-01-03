/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = 0, c = 0, sum = 0;
        // calculate the lowest digit
        sum = l1->val + l2->val + c;
        r = sum % 10;
        c = sum >= 10;
        ListNode *ret = new ListNode(r);    // lowest digit
        ListNode *end = ret;    // pointer to the highest digit
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2) {
            // calculate this digit
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            r = sum % 10;
            c = sum >= 10;
            // append result
            ListNode *new_node = new ListNode(r);
            new_node->val = r;
            end->next = new_node;
            end = end->next;
            // advance to the next digit
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        // If there are remaining carry in the highest digit
        if (c) {
            ListNode *new_node = new ListNode(c);
            end->next = new_node;
        }
        return ret;
    }
};
