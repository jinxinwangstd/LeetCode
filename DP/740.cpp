#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector< pair<int, int> > freq;
        for (int i = 0; i < n; i++) {
            if (freq.empty() || freq.back().first != nums[i])
                freq.push_back(make_pair(nums[i], 1));
            else
                freq.back().second++;
        }
        n = freq.size();
        vector<int> table(n + 1, 0);
        table[n - 1] = (freq[n - 1].first) * (freq[n - 1].second);
        for (int i = n - 2; i >= 0; i--) {
            table[i] = table[i + 2] + (freq[i].first) * (freq[i].second);
            if (freq[i].first + 1 < freq[i + 1].first)
                table[i] = max(table[i], table[i + 1] + (freq[i].first * freq[i].second));
            else
                table[i] = max(table[i], table[i + 1]);
        }
        return table[0];
    }
};
