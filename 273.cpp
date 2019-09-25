class Solution {
public:
    string names[12] = {"", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion"};
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        string res;
        int index = 0;
        while (num) {
            int three_digits = num % 1000;
            if (three_digits) {
                res = names[index / 3].empty() ? res : " " + names[index / 3] + res;
                int two_digits = three_digits % 100;
                int first = two_digits % 10;
                int second = two_digits / 10;
                int third = three_digits / 100;
                if (two_digits == 0)
                    ;
                else if (two_digits < 20)
                    res = " " + digits[two_digits] + res;
                else {
                    res = first ? " " + digits[first] + res : res;
                    res = " " + tens[second - 2] + res;
                }
                if (third > 0)
                    res = " " + digits[third] + " Hundred" + res;
            }
            num /= 1000;
            index += 3;
        }
        res.erase(res.begin());
        return res;
    }
};
