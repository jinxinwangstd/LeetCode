class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        while (idx < n) {
            int cur = nums[idx], pos = idx;
            while (cur) {
                if (nums[pos] != pos + 1)
                    nums[pos] = 0;
                pos = cur - 1;
                if (cur != nums[pos]) {
                    cur = nums[pos];
                    nums[pos] = pos + 1;
                }
                else
                    cur = 0;
            }
            idx++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (!nums[i])
                res.push_back(i + 1);
        return res;
    }
};

/*
 * Use array index to record appeared array elements
 */
