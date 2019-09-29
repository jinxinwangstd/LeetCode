class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int val) {
        vector<int> new_elem(2, val);
        bst.insert(new_elem);
        set<vector<int>>::iterator iter = bst.find(new_elem);
        int start = val, end = val;
        set<vector<int>>::iterator iter_before = bst.end(), iter_after = bst.end();
        if (iter != bst.begin())
            iter_before = prev(iter, 1);
        if (iter != bst.end())
            iter_after = next(iter, 1);
        // overlaps with the interval before
        if (iter_before != bst.end() && (*iter_before)[1] >= val - 1) {
            start = (*iter_before)[0];
            end = max(val, (*iter_before)[1]);
            bst.erase(iter_before);
        }
        // overlaps with the interval after
        if (iter_after != bst.end() && 
        ((*iter_after)[0] == val + 1 || (*iter_after)[0] == val)) {
            end = max(end, (*iter_after)[1]);
            bst.erase(iter_after);
        }
        bst.erase(iter);
        new_elem[0] = start;
        new_elem[1] = end;
        bst.insert(new_elem);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (set<vector<int>>::iterator iter = bst.begin(); iter != bst.end(); iter++)
            res.push_back(*iter);
        return res;
    }
private:
    set<vector<int>> bst;
};
