#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Solution {
public:
    void reorder(vi& seq, int start, int end) {
        // put the root value into the inorder position
        int root = seq[start];
        int root_pos = start;
        while (root_pos + 1 < end && seq[root_pos + 1] < root)
            root_pos++;
        // put the left subtree nodes into the inorder position
        for (int i = start + 1; i <= root_pos; ++i)
            seq[i - 1] = seq[i];
        seq[root_pos] = root;
        // reorder the left subtree and the right subtree
        if (root_pos != start)
            reorder(seq, start, root_pos);
        if (root_pos + 1 < end)
            reorder(seq, root_pos + 1, end);
        return;
    }
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return true;
        reorder(preorder, 0, preorder.size());
        for (int i = 1; i < preorder.size(); ++i)
            if (preorder[i] < preorder[i - 1])
                return false;
        return true;
    }
};
