class MyCircularQueue {
public:
    /* Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.assign(k, 0);
        front = 0;
        back = 0;
        size = 0;
    }

    /* Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        q[back++] = value;
        if (back == q.size())
            back = 0;
        size++;
        return true;
    }

    /* Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        front++;
        if (front == q.size())
            front = 0;
        size--;
        return true;
    }

    /* Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    /* Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return back == 0 ? q.back() : q[back - 1];
    }
    
    /* Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /* Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == q.size(); 
    }
private:
    vector<int> q;
    int front, back, size;
};
