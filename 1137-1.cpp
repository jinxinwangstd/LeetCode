class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 0, cur = 0, idx = 0;
        while (idx != n) {
            first = second;
            second = third;
            third = cur;
            cur = first + second + third;
            idx++;
        }
        return cur;
    }
};
