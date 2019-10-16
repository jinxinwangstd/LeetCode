class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n  = arr.size();
        int new_n = 0;
        int i = 0;
        while (new_n < n) {
            if (arr[i] == 0)
                new_n += 2;
            else
                new_n += 1;
            i++;
        }
        i--;
        int j = n - 1;
        if (new_n > n)
            arr[j--] = arr[i--];
        while (j >= 0) {
            if (arr[i] == 0) {
                arr[j--] = 0;
                arr[j--] = 0;
            }
            else
                arr[j--] = arr[i];
            i--;
        }
        return;
    }
};
