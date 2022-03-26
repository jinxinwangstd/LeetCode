class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        vector<int> res;
        for (auto query: queries) {
            res.push_back(prefix[query[1]] ^ (query[0] ? prefix[query[0] - 1] : 0));
        }
        return res;
    }
};
