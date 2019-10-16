class FenwickTree {
private:
    vector<int> ft;
    int lowbit(int x) {
        return x & -x;
    }
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int querySum(int b) {
        int sum = 0;
        for (; b > 0; b -= lowbit(b))
            sum += ft[b];
        return sum;
    }
    int querySum(int a, int b) {
        return querySum(b) - (a > 1 ? querySum(a - 1) : 0);
    }
    void add(int k, int v) {
        int n = ft.size();
        for (; k < n; k += lowbit(k))
            ft[k] += v;
        return;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int64_t> prefix;

        prefix.push_back(0);
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix.push_back(sum);
            // the lower bound of the prefix sum of a smaller prefix range
            prefix.push_back(sum - upper);
            // the upper bound of the prefix sum of a smaller prefix range
            prefix.push_back(sum - lower);
        }
        // make elements unique
        sort(prefix.begin(), prefix.end());
        int m = unique(prefix.begin(), prefix.end()) - prefix.begin();
        prefix.resize(m);
        // the fenwick tree is used to store the frequency of each prefix sum 
        FenwickTree ft(m);
        int ans = 0;
        sum = 0;
        int zero = lower_bound(prefix.begin(), prefix.end(), 0) - prefix.begin() + 1;
        ft.add(zero, 1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int a = lower_bound(prefix.begin(), prefix.end(), sum - upper) - prefix.begin() + 1;
            int b = lower_bound(prefix.begin(), prefix.end(), sum - lower) - prefix.begin() + 1;
            // if the prefix sum of [0, j) lies in [a, b], then the sum of [j, i] would be in [lower, bound] 
            ans += ft.querySum(a, b);
            // record the appearance of current prefix sum
            int k = lower_bound(prefix.begin(), prefix.end(), sum) - prefix.begin() + 1;
            ft.add(k, 1);
        }
        return ans;
    }
};
