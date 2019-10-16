class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> heap;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (heap.size() < k)
                    heap.push(matrix[i][j]);
                else {
                    if (matrix[i][j] < heap.top()) {
                        heap.pop();
                        heap.push(matrix[i][j]);
                    }
                }
            }
        return heap.top();
    }
};
