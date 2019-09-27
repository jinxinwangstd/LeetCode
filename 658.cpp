class Solution {
public:
    bool firstCloser(int a, int b, int target) {
        return abs(a - target) < abs(b - target);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int index = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        int l, r;
        if (index >= n)
            l = r = n - 1;
        else if (index == 0)
            l = r = 0;
        else {
            if (firstCloser(arr[index], arr[index - 1], x))
                l = r = index;
            else
                l = r = index - 1;
        }
        while (r - l + 1 < k) {
            if (r + 1 >= n)
                l--;
            else if (l - 1 < 0)
                r++;
            else {
                if (firstCloser(arr[r + 1], arr[l - 1], x))
                    r++;
                else
                    l--;
            }
        }
        vector<int> res;
        for (int i = l; i <= r; i++)
            res.push_back(arr[i]);
        return res;
    }
};
