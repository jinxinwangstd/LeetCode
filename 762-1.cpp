class Solution {
public:
    int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int countSetBits(int num) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (num >> i) & 1;
        }
        return res;
    }
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        vector<int> vec_primes(primes, primes + 11);
        for (int i = L; i <= R; i++) {
            int num = countSetBits(i);
            res += binary_search(vec_primes.begin(), vec_primes.end(), num);
        }
        return res;
    }
};
