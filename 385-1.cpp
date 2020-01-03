/*
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate its implementation.
class NestedInteger {
public:
    // Constructor initialize an empty nested list.
    NestedInteger();

    // Constructor initialize a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer into it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};
*/

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> list;
        string num;
        for (char c : s) {
            if (c == '[') {
                NestedInteger ni;
                list.push(ni);
            }
            else if (isdigit(c)) {
                if (num.empty()) {
                    NestedInteger ni;
                    list.push(ni);
                }
                num.push_back(c);
            }
            else {
                if (!num.empty()) {
                    NestedInteger ni = list.top();
                    list.pop();
                    ni.setInteger(stoi(num));
                    num.clear();
                    list.top().add(ni);
                }
                if (c == ']' && list.size() > 1) {
                    NestedInteger ni = list.top();
                    list.pop();
                    list.top().add(ni);
                }
            }
        }
        if (!num.empty()) {
            NestedInteger ni(stoi(num));
            num.clear();
            list.push(ni);
        }
        return list.top();
    }
};
