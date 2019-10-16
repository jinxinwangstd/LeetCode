class MovingAverage {
public:
    /* Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        if (q.size() == n) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (double)sum / q.size();
    }
private:
    queue<int> q;
    int n, sum;
};
