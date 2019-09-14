#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

/*
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        queue<Node*> q;
        int num = 1;
        q.push(root);
        int height = 0;
        while (!q.empty()) {
            height++;
            int next_num = 0;
            while (num) {
                Node *node = q.front();
                q.pop();
                num--;
                for (int i = 0; i < node->children.size(); i++) {
                    q.push(node->children[i]);
                    next_num++;
                }
            }
            num = next_num;
        }
        return height;
    }
};
