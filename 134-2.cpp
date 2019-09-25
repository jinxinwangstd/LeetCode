// Greedy
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
            diff[i] = gas[i] - cost[i];
        int total_left = accumulate(diff.begin(), diff.end(), 0);
        if (total_left < 0)
            return -1;
        vector<int> left(n, 0);
        left[0] = diff[0];
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (left[i - 1] < 0) {
                start = i;
                left[i] = diff[i];
            }
            else
                left[i] = left[i - 1] + diff[i];
        }
        return start;
    }
};
