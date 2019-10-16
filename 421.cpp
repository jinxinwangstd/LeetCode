struct Trie {
    vector<vector<int>> trie;
    int total = 0;
    vector<bool> end;
    Trie() {
        trie.assign(1, vector<int>(2, -1));
        end.assign(1, false);
    }
    void insert(int num) {
        int p = 0;
        for (int i = 31; i >= 0; i--) {
            int digit = (num >> i) & 1;
            if (trie[p][digit] == -1) {
                trie[p][digit] = ++total;
                trie.push_back(vector<int>(2, 0));
                end.push_back(false);
            }
            p = trie[p][digit];
        }
        end[p] = true;
        return;       
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums)
            trie.insert(num);
        int max_res = 0;
        for (int num : nums) {
            int p = 0, res = 0;
            for (int i = 31; i >= 0; i--) {
                int digit = (num >> i) & 1;
                int reverse = 1 - digit;
                if (trie[p][reverse] > -1) {
                    p = trie[p][reverse];
                    res = (res << 1) | 1;
                }
                else {
                    p = trie[p][digit];
                    res = (res << 1) | 0;
                }
            }
            max_res = max(res, max_res);
        }
        return max_res;
    }
};
