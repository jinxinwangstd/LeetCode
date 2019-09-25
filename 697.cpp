class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (!m.count(num)) {
                m[num] = vector<int>(3, 0);
                m[num][0] = 1;
                m[num][1] = m[num][2] = i;
            }
            else {
                m[num][0]++;
                m[num][2] = i;
            }
        }
        int count = 0, range = INT_MAX;
        for (unordered_map<int, vector<int>>::iterator iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second[0] > count) {
                count = iter->second[0];
                range = iter->second[2] - iter->second[1] + 1;
            }
            else if (iter->second[0] == count)
                range = min(range, iter->second[2] - iter->second[1] + 1);
        }
        return range;
    }
};
