class Solution {
public:
    string toHex(int num) {
        if (!num)
            return "0";
        string res;
        while (num) {
            int digit = num & 15;
            if (digit < 10)
                res.push_back('0' + digit);
            else
                res.push_back('a' + digit - 10);
            // arithmetic right shift
            num >>= 4;
            if (num < 0)
                num &= ~(15 << 28);
        }
        int n = res.size();
        for (int i = 0; i <= (n - 1) / 2; i++)
            swap(res[i], res[n - 1 - i]);
        return res;
    }
};
