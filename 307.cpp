// Binary Indexed Tree
class NumArray {
private:
    vector<int> C;
    int lowBit(int x) {
        return x & (-x);
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        C.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int v = val - sumRange(i, i);
        i++;
        for (; i < (int)C.size(); i += lowBit(i))
            C[i] += v; 
    }

    int sumRange(int i) {
        int sum = 0;
        for (; i > 0; i -= lowBit(i))
            sum += C[i];
        return sum;
    }

    int sumRange(int i, int j) {
        i++;
        j++;
        return sumRange(j) - (i > 1 ? sumRange(i - 1) : 0);
    }
};

