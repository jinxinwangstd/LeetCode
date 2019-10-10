// Segment Tree for Range Sum Query
class SegmentTree {
private:
    vector<int> arr, sumv;
    int n;
    // o is the index of the node in the heap
    void pushup(int o) {
        sumv[o] = sumv[o << 1] + sum[o << 1 | 1];
    }
    // 
    void build(int o, int l, int r) {
        if (l == r) {
            sumv[o] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushup(o);
        return;
    }
public:
    SegmentTree(const vector<int>& _A) {
        arr = _A;
        n = arr.size();
        sumv.assign(n << 2, 0);
        build(1, 0, n - 1);
    }
    void change(int o, int l, int r, int q, int v) {
        if (l == r) {
            sumv[o] += v;
            return;
        }
        int mid = (l + r) / 2;
        if (q <= mid)
            change(o, l, mid, q, v);
        else
            change(o, mid + 1, r, q, v);
        pushup(o);
        return;
    }
    int querySum(int o, int l, int r, int ql, int qr) {
        if (ql <= l && qr >= r)
            return sumv[o];
        int sum = 0;
        int mid = (l + r) / 2;
        if (ql <= mid)
            sum += querySum(o << 1, l, mid, ql, qr);
        if (qr > mid)
            sum += querySum(o << 1 | 1, mid + 1, r, ql, qr);
        return sum;
    }
};
