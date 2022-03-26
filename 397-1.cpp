class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        int64_t num = n;
        while (num > 1) {
            if (num & 1) {
                if (num & 2) {
                    num++;
                }
                else {
                    num--;
                }
            }
            else {
                num >>= 1;
            }
            res++;
        }
        return res;
    }
};
