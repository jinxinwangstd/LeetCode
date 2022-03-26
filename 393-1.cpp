class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; i++) {
            int idx = 7, num_ones = 0;
            while (idx >= 0) {
                if (!(data[i] & (1 << idx)))
                    break;
                idx--;
                num_ones++;
            }
            if (num_ones == 1 || num_ones > 4)
                return false;
            if (!num_ones)
                continue;
            num_ones--;
            while (num_ones) {
                i++;
                if (i >= n)
                    return false;
                if (!((data[i] & (1 << 7)) && !(data[i] & (1 << 6))))
                    return false;
                num_ones--;
            }
        }
        return true;
    }
};
