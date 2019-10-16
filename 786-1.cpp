struct MyPair {
    int x, y;
    int x_i, y_i;

    MyPair(int _x, int _y, int _x_i, int _y_i) : x(_x), y(_y), x_i(_x_i), y_i(_y_i) {}
    // the actual meaning of this operator is '>', we define '<' as '>' to make the default priority queue as the min-heap
    bool operator < (const MyPair& other) const {
        return x * other.y > y * other.x;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        priority_queue<MyPair> heap;
        for (int i = 1; i < n; i++)
            heap.push(MyPair(A[0], A[i], 0, i));
        while (K--) {
            auto cur = heap.top();
            heap.pop();
            if (!K)
                return vector<int>{cur.x, cur.y};

            if (cur.x_i + 1 < cur.y_i) {
                int next_x_i = cur.x_i + 1;
                int next_y_i = cur.y_i;
                heap.push(MyPair(A[next_x_i], A[next_y_i], next_x_i, next_y_i));
            }
        }
        return vector<int>{-1, -1};
    }
};

/*
 * Greedy + Heap
 */
