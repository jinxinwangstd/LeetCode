class Solution {
public:
    bool check(vector<int>& sweetness, int K, int min) {
        int sum = 0;
        for (int val : sweetness) {
            sum += val;
            if (sum >= min) {
                K--;
                sum = 0;
            }
        }
        return K < 0;
    }
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int n = sweetness.size();
        int sum = accumulate(sweetness.begin(), sweetness.end(), 0);
        int l = 1, r = (int)floor(sum / (double)(K + 1)), mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (check(sweetness, K, mid))
                l = mid;
            else
                r = mid;
        }
        if (check(sweetness, K, r))
            return r;
        else
            return l;
    }
};

/*
 * Binary search + Greedy checking.
 */
