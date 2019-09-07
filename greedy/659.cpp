#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq, tails;
        for (int i = 0; i < n; i++)
            freq[nums[i]]++;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (freq[num] > 0) {
                freq[num]--;
                if (tails[num - 1] > 0) {
                    tails[num - 1]--;
                    tails[num]++;
                }
                else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                    freq[num + 1]--;
                    freq[num + 2]--;
                    tails[num + 2]++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
