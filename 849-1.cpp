class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int max_gap = 0;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                if (idx == -1)
                    max_gap = max(max_gap, i - idx - 1);
                else
                    max_gap = max(max_gap, (i - idx) / 2);
                idx = i;
            }
        }
        max_gap = max(max_gap, n - 1 - idx);
        idx = seats.size();
        return max_gap;
    }
};
