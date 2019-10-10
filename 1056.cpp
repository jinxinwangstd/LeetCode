class Solution {
public:
    int mapping[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    bool confusingNumber(int N) {
        int rotated = 0, original = N;
        while (N) {
            int digit = N % 10;
            N /= 10;
            if (mapping[digit] >= 0)
                rotated = rotated * 10 + mapping[digit];
            else
                return false;
        }
        return rotated != original;
    }
};

