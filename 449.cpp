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

class Codec {
public:
    void postorderTraversal(TreeNode *root, string& data) {
        if (!root)
            return;
        postorderTraversal(root->left, data);
        postorderTraversal(root->right, data);
        // encode an integer to byte sequence
        char bytes[4];
        memcpy(bytes, &root->val, sizeof(int));
        for (int i = 0; i < 4; ++i)
            data.push_back(bytes[i]);
        return;
    }
    // Encodes a tree to a single string
    string serialize(TreeNode *root) {
        string ret;
        postorderTraversal(root, ret);
        return ret;
    }
    TreeNode* deserializeHelper(int lower, int upper, vi& values) {
        if (values.empty())
            return NULL;
        int root_value = values.back();
        if (root_value < lower || root_value > upper)
            return NULL;

        values.pop_back();
        TreeNode *root = new TreeNode(root_value);
        root->right = deserializeHelper(root_value, upper, values);
        root->left = deserializeHelper(lower, root_value, values);
        return root;
    }
    // Decodes your encoded data into tree
    TreeNode* deserialize(string data) {
        int num_values = (int)data.size() / 4;
        vi values(num_values);
        for (int i = 0; i < num_values; ++i)
            memcpy(&values[i], &data[4 * i], sizeof(int));
        return deserializeHelper(INT_MIN, INT_MAX, values);
    }
};
