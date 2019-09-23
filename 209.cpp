class Solution {
public:
    int rangeSum(vector<int>& pre, int i, int j) {
        return pre[j] - (i > 0 ? pre[i - 1] : 0);
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        int res = n + 1;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1, mid;
            while (r - l > 1) {
                mid = l + (r - l) / 2;
                if (rangeSum(pre, i, mid) < s)
                    l = mid;
                else
                    r = mid;
            }
            if (rangeSum(pre, i, l) >= s)
                res = min(res, l - i + 1);
            else if (rangeSum(pre, i, r) >= s)
                res = min(res, r - i + 1);
        }
        return res == n + 1 ? 0 : res;
    }
};
