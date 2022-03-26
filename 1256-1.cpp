class Solution {
public:
    string encode(int num) {
        if (num == 0)
            return "";
        int offset = 1;
        while (num >= offset) {
            num -= offset;
            offset *= 2;
        }
        string res;
        while (offset > 1) {
            offset /= 2;
            res += to_string(num / offset);
            num -= (num / offset) * offset;
        }
        return res;
    }
};
