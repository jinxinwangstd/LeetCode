class Solution {
public:
    int ipToInt(string ip) {
        int res = 0, start = 0, end = 0;
        for (int i = 0; i < 3; i++) {
            end = ip.find('.', start);
            res |= stoi(ip.substr(start, end - start));
            res <<= 8;
            start = end + 1;
        }
        res |= stoi(ip.substr(start));
        return res;
    }
    string intToIp(int num) {
        string res;
        for (int i = 3; i > 0; i--) {
            res += to_string((num >> (8 * i)) & 0xff);
            res += ".";
        }
        res += to_string(num & 0xff);
        return res;
    }
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        int cur = ipToInt(ip);
        while (n > 0) {
            int count = 1, bit_idx = 0;
            while ((count << 1) <= n && bit_idx < 32 && !(cur & (1 << bit_idx))) {
                count <<= 1;
                bit_idx += 1;
            }
            res.push_back(intToIp(cur) + "/" + to_string(32 - bit_idx));
            cur += count;
            n -= count;
        }
        return res;
    }
};
