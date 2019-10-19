class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> next_greater;
        int m = nums1.size(), n = nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] >= s.top())
                s.pop();
            if (s.empty())
                next_greater[nums2[i]] = -1;
            else
                next_greater[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for (int i = 0; i < m; i++)
            nums1[i] = next_greater[nums1[i]];
        return nums1;
    }
};

/*
 * Monotonic stack.
 */
