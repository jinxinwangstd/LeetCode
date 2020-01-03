class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> freq;
        for (int val : hand)
            freq[val]++;
        while (!freq.empty()) {
            int start = freq.begin()->first;
            int end = start + W;
            for (int i = start; i < end; i++) {
                freq[i]--;
                if (freq[i] < 0)
                    return false;
                if (freq[i] == 0)
                    freq.erase(i);
            }
        }
        return true;
    }
};

/*
 * Balanced binary search tree
 */
