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
    bool isBinarySearchTree(TreeNode *root, int *size, int *left, int *right) {
        int left_size = 0, right_size = 0;
        int left_sub_left, left_sub_right;
        int right_sub_left, right_sub_right;
        if (!root->left && !root->right) {
            *left = root->val;
            *right = root->val;
            *size = 1;
            largest_size = max(largest_size, *size);
            return true;
        }
        bool left_BST = true, right_BST = true;
        if (root->left)
            left_BST = isBinarySearchTree(root->left, &left_size, &left_sub_left, &left_sub_right);
        if (root->right)
            right_BST = isBinarySearchTree(root->right, &right_size, &right_sub_left, &right_sub_right);
        if (!left_BST || !right_BST)
            return false;
        if (!root->left) {
            if (root->val < right_sub_left) {
                *left = root->val;
                *right = right_sub_right;
                *size = 1 + right_size;
                largest_size = max(largest_size, *size);
                return true;
            }
            else
                return false;
        }
        else if (!root->right) {
            if (root->val > left_sub_right) {
                *left = left_sub_left;
                *right = root->val;
                *size = 1 + left_size;
                largest_size = max(largest_size, *size);
                return true;
            }
            else
                return false;
        }
        else {
            if (left_sub_right < root->val && root->val < right_sub_left) {
                *left = left_sub_left;
                *right = right_sub_right;
                *size = left_size + 1 + right_size;
                largest_size = max(largest_size, *size);
                return true;
            }
            else
                return false;
        }   
    }
    int largestBSTSubtree(TreeNode *root) {
        if (!root)
            return 0;
        largest_size = 0;
        int size, left, right;
        isBinarySearchTree(root, &size, &left, &right);
        return largest_size;
    }
private:
    int largest_size;
};
