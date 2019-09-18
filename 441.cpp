class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if ((1 + mid) * (int64_t)mid / 2 <= n)
                l = mid;
            else
                r = mid;
        }
        if ((1 + r) * (int64_t)r / 2 <= n)
            return r;
        else
            return l;
    }
};
