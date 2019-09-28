// random number with different probability
// binary search to find the number in prefix sum array
class Solution {
public:
    // w[i] is the weight of i to be picked
    // which means i has the probability of w[i] / sum(w) to be picked
    // w describe the probability distribution
    Solution(vector<int>& w) {
        int n = w.size();
        pre_sum = vector<int>(n, 0);
        pre_sum[0] = w[0];
        total = w[0];
        for (int i = 1; i < n; i++) {
            pre_sum[i] = pre_sum[i - 1] + w[i];
            total += w[i];
        }
        return;
    }

    int pickIndex() {
        int n = pre_sum.size();
        // generate a random number in [0. total - 1]
        int pick = rand() % total;
        int index = distance(pre_sum.begin(), upper_bound(pre_sum.begin(), pre_sum.end(), pick));
        return index;
    }
private:
    vector<int> pre_sum;
    int total;
};
