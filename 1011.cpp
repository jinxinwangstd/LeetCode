class Solution {
public:
    int countDays(vector<int>& weights, int capacity) {
        int res = 0, left = 0;
        int i = 0, n = weights.size();
        while (i < n) {
            if (weights[i] > left) {
                res++;
                left = capacity;
            }
            left -= weights[i];
            i++;
            if (left < 0)
                return INT_MAX;
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = accumulate(weights.begin(), weights.end(), 0), mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (countDays(weights, mid) <= D)
                r = mid;
            else
                l = mid;
        }
        if (countDays(weights, l) <= D)
            return l;
        else
            return r;
    }
};
