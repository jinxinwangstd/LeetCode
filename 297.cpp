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
    // DFS is better than BFS because of cutting down a lot of null nodes
    void rserialize(TreeNode *root, string& data) {
        if (!root) {
            data += "null,";
            return;
        }
        data += to_string(root->val) + ",";
        rserialize(root->left, data);
        rserialize(root->right, data);
        return;
    }
    // Encodes a tree to a single string
    string serialize(TreeNode *root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }
    TreeNode* rdeserialize(vector<string>& values, int *index) {
        if (values[*index] == "null") {
            (*index)++;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(values[*index]));
        (*index)++;
        root->left = rdeserialize(values, index);
        root->right = rdeserialize(values, index);
        return root;
    }
    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        // split values into a vector
        int start = 0, end = start;
        vector<string> values;
        while (start < data.size()) {
            end = data.find(',', start);
            values.push_back(data.substr(start, end - start));
            start = end + 1;
        }
        int index = 0;
        return rdeserialize(values, &index);
    }
};
