class Solution {
public:
    int rotated[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    bool isStrobogrammatic(string num) {
        int n = num.size();
        int mid = floor((n - 1) / 2);
        for (int i = 0; i <= mid; i++) {
            int ch1 = num[i] - '0';
            int ch2 = num[n - 1 - i] - '0';
            if (rotated[ch1] != ch2)
                return false;
        }
        return true;
    }
};

/*
 * Array indexing
 */
