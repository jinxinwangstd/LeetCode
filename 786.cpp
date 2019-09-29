class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        int a_num = a.first * b.second, b_num = b.first * a.second;
        return a_num < b_num;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        vector<pair<int, int>> record;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (A[i] < A[j])
                    record.push_back(make_pair(A[i], A[j]));
        sort(record.begin(), record.end(), compare);
        vector<int> res(2, 0);
        res[0] = record[K - 1].first;
        res[1] = record[K - 1].second;
        return res;       
    }
};
