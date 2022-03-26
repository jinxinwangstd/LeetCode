class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> record;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            record.insert(A[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                A[j] |= A[j + 1];
                record.insert(A[j]);
            }
        }
        return record.size();
    }
};
