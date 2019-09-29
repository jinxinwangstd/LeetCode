class Solution {
public:
    int shortestSubarrayHelper(vector<int>& A, int K, int l, int r) {
        if (l == r)
            return A[l] >= K ? 1 : -1;
        int mid = l + (r - l) / 2;
        int l_len = shortestSubarrayHelper(A, K, l, mid);
        int r_len = shortestSubarrayHelper(A, K, mid + 1, r);
        vector<int> pre_post(r - l + 1, 0);
        pre_post[mid - l] = A[mid];
        for (int i = mid - 1; i >= l; i--)
            pre_post[i - l] = pre_post[i - l + 1] + A[i];
        pre_post[mid + 1 - l] = A[mid + 1];
        for (int i = mid + 2; i <= r; i++)
            pre_post[i - l] = pre_post[i - l - 1] + A[i];
        int i1 = mid, i2 = mid + 1;
        while ((i1 > l || i2 < r) && pre_post[i1 - l] + pre_post[i2 - l] < K) {
            if (i1 <= l)
                i2++;
            else if (i2 >= r)
                i1--;
            else {
                if (A[i1 - 1] > A[i2 + 1])
                    i1--;
                else
                    i2++;
            }
        }
        int res = INT_MAX;
        if (l_len > 0)
            res = min(res, l_len);
        if (r_len > 0)
            res = min(res, r_len);
        if (pre_post[i1 - l] + pre_post[i2 - l] >= K)
            res = min(res, i2 - i1 + 1);
        return res == INT_MAX ? -1 : res;
    }        
    int shortestSubarray(vector<int>& A, int K) {
        return shortestSubarrayHelper(A, K, 1, A.size() - 1);         
    }
};
