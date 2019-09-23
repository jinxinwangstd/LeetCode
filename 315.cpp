// Binary Indexed Tree
class FenwickTree {
private:
    vector<int> C;
    int lowBit(int x) {
        return x & (-x);
    }
public:
    FenwickTree(int n) {
        C.assign(n + 1, 0);
    }
    void change(int k, int v) {
        for (; k < (int)C.size(); k += lowBit(k))
            C[k] += v;
    }
    int rangeQuery(int b) {
        int sum = 0;
        for (; b > 0; b -= lowBit(b))
            sum += C[b];
        return sum;
    }
    int rangeQuery(int a, int b) {
        return rangeQuery(b) - (a > 1 ? 0 : rangeQuery(a - 1));
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();
        // 离散化
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        int offset = -min + 1;
        int n = max + offset;
        FenwickTree ft(n);  // record the occurrence of elements
        vector<int> res(nums.size(), 0);
        // linear scan from right to left and query the sum of occurrence of element smaller than it
        for (int i = nums.size() - 1; i >= 0; i--) {
            ft.change(nums[i] + offset, 1);
            res[i] = ft.rangeQuery(nums[i] + offset - 1);
        }
        return res;
    }
};
