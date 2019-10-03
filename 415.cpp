class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string& res = n1 > n2 ? num1 : num2;
        int n_res = max(n1, n2);
        int d = 1;
        int sum, carry = 0;
        while (d <= n_res) {
            if (n1 - d < 0) {
                sum = (int)(num2[n2 - d] - '0') + carry;
                carry = sum / 10;
                res[n_res - d] = (sum % 10) + '0';
            }
            else if (n2 - d < 0) {
                sum = (int)(num1[n1 - d] - '0') + carry;
                carry = sum / 10;
                res[n_res - d] = (sum % 10) + '0';
            }
            else {
                sum = (int)(num1[n1 -d] - '0') + (int)(num2[n2 - d] - '0') + carry;
                carry = sum / 10;
                res[n_res - d] = (sum % 10) + '0';
            }
            d++;
        }
        if (carry)
            res.insert(res.begin(), (char)(carry + '0'));
        return res;
    }
};
