class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int dist = abs(nums[i] - nums[j]);
                if (heap.size() < k)
                    heap.push(dist);
                else {
                    if (dist < heap.top()) {
                        heap.pop();
                        heap.push(dist);
                    }
                }
            }
        return heap.top();
    }
};
