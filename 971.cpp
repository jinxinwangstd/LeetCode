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
    bool preorderTraverse(TreeNode *root, vector<int>& seq, vector<int>& voyage, vector<int>& flipped) {
        if (root->left) {
            seq.push_back(root->left->val);
            int index = seq.size() - 1;
            if (seq[index] != voyage[index]) {
                if (root->right && root->right->val == voyage[index]) {
                    TreeNode *temp = root->right;
                    root->right = root->left;
                    root->left = temp;
                    flipped.push_back(root->val);
                    seq[index] = root->left->val;
                }
                else
                    return false;
            }
            if (!preorderTraverse(root->left, seq, voyage, flipped))
                return false;
        }
        if (root->right) {
            seq.push_back(root->right->val);
            int index = seq.size() - 1;
            if (seq[index] != voyage[index])
                return false;
            if (!preorderTraverse(root->right, seq, voyage, flipped))
                return false;
        }
        return true;
    }
    vector<int> flipMatchVoyage(TreeNode *root, vector<int>& voyage) {
        vector<int> flipped;
        if (root->val != voyage[0]) {
            flipped.push_back(-1);
            return flipped;
        }
        vector<int> seq;
        seq.push_back(root->val);
        bool res = preorderTraverse(root, seq, voyage, flipped);
        if (!res) {
            flipped.clear();
            flipped.push_back(-1);
        }
        return flipped;
    }
};
