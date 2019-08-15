#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *anchor = new ListNode(val ? 0 : 1);
        anchor->next = head;
        ListNode *cur = anchor;
        while (cur->next) {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        ListNode *ret = anchor->next;
        delete(anchor);
        return ret;
    }
};
