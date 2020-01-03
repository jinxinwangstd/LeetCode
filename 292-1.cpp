class Solution {
public:
    deque<bool> dp;
    bool canWinNim(int n) {
        if (n <= 3)
            return true;
        for (int i = 1; i <= 3; i++)
            dp.push_back(true);
        int cur = 3;
        while (cur < n) {
            bool nxt = false;
            for (deque<bool>::iterator iter = dp.begin(); iter != dp.end(); iter++)
                nxt = nxt || !(*iter);
            dp.pop_front();
            dp.push_back(nxt);
            cur++;
        }
        return dp.back();
    }
};

/*
 * Minimax + dynamic programming
 */
