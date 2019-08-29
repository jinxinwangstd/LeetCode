#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* findNode(TreeNode *root, int target, TreeNode **parent) {
        *parent = NULL;
        for (;;) {
            if (!root)
                return NULL;
            if (root->val == target)
                return root;
            else if (root->val > target) {
                *parent = root;
                root = root->left;
            }
            else {
                *parent = root;
                root = root->right;
            }
        }
    }
    TreeNode *deleteNode(TreeNode *root, int key) {
        // find the node to be deleted
        TreeNode *node, *parent;
        node = findNode(root, key, &parent);
        if (!node)
            return root;
        if (!node->left && !node->right) {
            if (!parent)
                return NULL; 
            else if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
            return root;
        }
        // find the left node and right node in the BST and then replace the deleted node with the left or right
        if (node->left && !node->left->right) {
            node->val = node->left->val;
            node->left = node->left->left;
        }
        else if (node->left) {
            TreeNode *left = node->left;
            parent = node;
            while (left->right) {
                parent = left;
                left = left->right;
            }
            node->val = left->val;
            parent->right = left->left;
        }
        else if (node->right && !node->right->left) {
            node->val = node->right->val;
            node->right = node->right->right;
        }
        else {
            TreeNode *right = node->right;
            parent = node;
            while (right->left) {
                parent = right;
                right = right->left;
            }
            node->val = right->val;
            parent->left = right->right;
        }
        return root;
    }
};
