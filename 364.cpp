/*
class NestedInteger {
public:
    NestedInteger();

    NestedInteger(int value);
    // Return true if the NestedInteger holds a single integer
    bool isInteger() const;
    // Return the integer the NestedInteger holds
    int getInteger() const;

    void setInteger(int value) const;

    void add(const NestedInteger& ni);
    // Return the list the NestedInteger holds
    const vector<NestedInteger> &getList() const;
};
*/

class SelfTreeNode {
public:
    int val;
    int depth;
    vector<SelfTreeNode*> children;
    SelfTreeNode(int x) : val(x), depth(1), children(vector<SelfTreeNode*>()) {}
};

class Solution {
public:
    SelfTreeNode *createTree(vector<NestedInteger>& nestedList) {
        SelfTreeNode *root = new SelfTreeNode(0);
        int n = nestedList.size();
        for (int i = 0; i < n; i++) {
            NestedInteger ni = nestedList[i];
            if (ni.isInteger())
                root->val += ni.getInteger();
            else {
                SelfTreeNode *child = createTree(ni.getList());
                root->depth = max(root->depth, 1 + child->depth);
                root->children.push_back(child);
            }
        }
        return root;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        SelfTreeNode *root = createTree(nestedList);
        int res = 0;
        queue<SelfTreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            SelfTreeNode *node = q.front();
            q.pop();
            res += node->val * node->depth;
            for (int i = 0; i < node->children.size(); i++) {
                node->children[i]->depth = node->depth - 1;
                q.push(node->children[i]);
            }
        }
        return res;
    }
};
