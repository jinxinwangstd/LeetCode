class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top())
                s.pop();
            if (s.empty())
                res[i] = -1;
            else
                res[i] = s.top();
            s.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top())
                s.pop();
            if (res[i] == -1)
                if (!s.empty())
                    res[i] = s.top();
            s.push(nums[i]);
        }
        return res;
    }
};

/*
 * Monotonic stack
 */
