class Solution {
public:
    int mapping[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    int rotate(int num) {
        int res = 0;
        while (num) {
            int digit = num % 10;
            res *= 10;
            if (mapping[digit] < 0)
                return -1;
            else
                res += mapping[digit];
            num /= 10;
        }
        return res;
    }
    bool confusingNumber(int N) {
        int rotated = rotate(N);
        return rotated > 0 && N != rotated;
    }
};

