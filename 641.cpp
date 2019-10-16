class MyCircularDeque {
public:
    /* Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        q.assign(k, 0);
        front = k - 1;
        back = 0;
        size = 0;
    }
    
    /* Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        q[front--] = value;
        size++;
        if (front < 0)
            front = q.size() - 1;
        return true;
    }
    
    /* Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        q[back++] = value;
        size++;
        if (back == q.size())
            back = 0;
        return true;
    }
    
    /* Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        front++;
        size--;
        if (front == q.size())
            front = 0;
        return true;
    }
    
    /* Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        back--;
        size--;
        if (back < 0)
            back = q.size() - 1;
        return true;
    }
    
    /* Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return front == q.size() - 1 ? q[0] : q[front + 1]; 
    }
    
    /* Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return back == 0 ? q.back() : q[back - 1]; 
    }
    
    /* Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0; 
    }
    
    /* Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == q.size(); 
    }
private:
    vector<int> q;
    int front, back, size;
};

