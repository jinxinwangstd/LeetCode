class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int num = 0;
        for (char c : S)
            if (c != '-')
                num++;
        if (!num)
            return "";
        int num_dashes = ceil(num / (double)K) - 1;
        string res(num + num_dashes, ' ');
        int count = K, index = res.size() - 1;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (!count) {
                    res[index--] = '-';
                    count = K;
                }
                res[index--] = toupper(S[i]);
                count--;
            }
        }
        return res;
    }
};

/*
 * String
 * Watch for edge cases
 */
