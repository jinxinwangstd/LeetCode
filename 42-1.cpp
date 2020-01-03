class Solution {
public:
    int trap(vector<int>& height) {
        // corner case: there is no space for storing rain
        if (height.empty())
            return 0;
        int length = (int) height.size();
        // use two arrays to record the maximum height to a specific bar's left and right
        int max_left[length], max_right[length];
        max_left[0] = 0;
        max_right[length - 1] = 0;
        // record the maximum left bar height
        for (int i = 1; i < length; i++)
            max_left[i] = max(max_left[i - 1], height[i - 1]);
        // record the maximum right bar height
        for (int i = 1; i < length; i++)
            max_right[length - 1 - i] = max(max_right[length - i], height[length - i]);
        int ret = 0;
        // Linear scan to calculate the rain volume for each bar
        for (int i = 0; i != length; ++i) {
            int h = min(max_left[i], max_right[i]);
            // for a specific bar, the rain it can store is the minimum of maximum bar to its both sides then minus its own height
            if (h >= height[i])
                ret += h - height[i];
        }
        return ret;
    }
};
