class MyQueue {
public:
    /* Initialize your data structure here. */
    MyQueue() {}
    /* Push element into the back of the queue. */
    void push(int x) {
        in.push(x);
    }
    /* Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int val = out.top();
        out.pop();
        return val;
    }
    /* Get the front element. */
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    /* Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in, out;
};

