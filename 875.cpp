class Solution {
public:
    int eatingHours(vector<int>& piles, int K) {
        int res = 0, n = piles.size();
        for (int i = 0; i < n; i++)
            res += (int)ceil(piles[i] / (double)K);
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int max_num = *max_element(piles.begin(), piles.end());
        int l = 1, r = max_num, mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (eatingHours(piles, mid) > H)
                l = mid;
            else
                r = mid;
        }
        if (eatingHours(piles, l) <= H)
            return l;
        else
            return r;
    }
};
