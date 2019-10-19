/*
class NestedInteger {
public:
    // Returns true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this nested integer holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};
*/

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        flatten(nestedList);
        return;
    }

    int next() {
        int val = q.front();
        q.pop_front();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    deque<int> q;
    void flatten(vector<NestedInteger>& nestedList) {
        for (auto ni : nestedList) {
            if (ni.isInteger())
                q.push_back(ni.getInteger());
            else
                flatten(ni.getList());
        }
        return;
    }
};
