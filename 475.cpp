#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

class Solution {
public:
    bool allCovered(vector<int>& houses, vector<int>& heaters, int r) {
        int m = houses.size(), n = heaters.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (houses[i] >= heaters[j] - r && houses[i] <= heaters[j] + r)
                i++;
            else
                j++;
        }
        return i == m;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = max(houses[houses.size() - 1], heaters[heaters.size() - 1]), mid;
        while (r - l > 1) {
            mid = l + (r - l) / 2;
            if (allCovered(houses, heaters, mid))
                r = mid;
            else
                l = mid;
        }
        if (allCovered(houses, heaters, l))
            return l;
        else
            return r;
    }
};
