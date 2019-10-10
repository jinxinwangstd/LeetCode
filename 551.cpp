class Solution {
public:
    bool checkRecord(string s) {
        int num_A = 0, num_L = 0;
        for (char c : s) {
            if (c == 'L') {
                num_L++;
                if (num_L > 2)
                    return false;
            }
            else {
                if (c == 'A') {
                    num_A++;
                    if (num_A > 1)
                        return false;
                }
                num_L = 0;
            }
        }
        return true;
    }
};
