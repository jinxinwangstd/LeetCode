class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            pos[nums[i]] = i;
        for (int i = 0; i < n; i++) {
            int rest = target - nums[i];    // calculate the other adder
            // the other number should be in the list and cannot be itself
            if (pos.count(rest) && pos[rest] != i) {
                res.push_back(i);
                res.push_back(pos[rest]);
                return res;
            }
        }
        return res;
    }
};

/*
 * Reverse indexing
 */
