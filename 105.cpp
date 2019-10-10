/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    TreeNode *buildTreeHelper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        // base case: the tree contains no value so that it would be an empty tree
        if (pre_start == pre_end)
            return NULL;
        // find the root node
        int root_value = preorder[pre_start];
        TreeNode *root = new TreeNode(root_value);
        // find the value range of the left subtree
        int left_in_start = in_start, left_pre_start = pre_start + 1, left_len = 0;
        while (inorder[left_in_start + left_len] != root_value)
            left_len++;
        // find the value range of the right subtree
        int right_in_start = in_start + left_len + 1, right_pre_start = left_pre_start + left_len, right_len = 0;
        right_len = pre_end - right_pre_start;
        // given the value range of preorder and inorder traversal, build two subtrees
        root->left = buildTreeHelper(preorder, left_pre_start, left_pre_start + left_len, inorder, left_in_start, left_in_start + left_len);
        root->right = buildTreeHelper(preorder, right_pre_start, right_pre_start + right_len, inorder, right_in_start, right_in_start + right_len);
        return root;
    }
    // This function builds the binary tree given the preorder and inorder traversal
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
