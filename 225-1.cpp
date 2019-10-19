class MyStack {
public:
    /* Initialize your data structure here. */
    MyStack() {}

    /* Push element x onto stack. */
    void push(int x) {
        if (!q2.empty())
            q2.push(x);
        else
            q1.push(x);
        last = x;
        return;
    }

    /* Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int>& target = q1.empty() ? q2 : q1;
        queue<int>& backup = q1.empty() ? q1 : q2;
        while (target.size() > 2) {
            backup.push(target.front());
            target.pop();
        }
        if (target.size() > 1) {
            backup.push(target.front());
            last = target.front();
            target.pop();
        }
        int val = target.front();
        target.pop();
        return val; 
    }

    /* Get the top element. */
    int top() {
        return last;
    }

    /* Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
    int last;
};
