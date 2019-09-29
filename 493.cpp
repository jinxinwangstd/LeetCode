class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        if (nums.size() == 2) {
            int res = 0;
            if ((int)ceil(nums[0] / (double)2) > nums[1])
                res++;
            if (nums[0] > nums[1])
                swap(nums[0], nums[1]);
            return res;
        }
        int mid = 0 + (nums.size() - 1) / 2;
        vector<int> left(nums.begin(), next(nums.begin(), mid + 1)),
            right(next(nums.begin(), mid + 1), nums.end());
        int res = 0;
        res += reversePairs(left);
        res += reversePairs(right);
        int n1 = left.size(), n2 = right.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if ((int)ceil(left[i] / (double)2) > right[j])
                j++;
            else {
                res += j;
                i++;
            }
        }
        if (i < n1)
            res += (n1 - i) * n2;
        // sort the whole array
        i = 0;
        j = 0;
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                nums[i + j] = left[i];
                i++;
            }
            else {
                nums[i + j] = right[j];
                j++;
            }
        }
        while (i < n1) {
            nums[i + j] = left[i];
            i++;
        }
        while (j < n2) {
            nums[i + j] = right[j];
            j++;
        }
        return res;
    }
};
