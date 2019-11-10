class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int maxSize;
    int currSize;
    int * queue;
    int front;
    int rear;
    MyCircularQueue(int k) {
        maxSize = k;
        currSize = 0;
        queue = (int *)calloc(k,sizeof(int));
        front = 0;
        rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(currSize == maxSize)
        {
            return false;
        }
        if(currSize == 0)
        {
            queue[rear] = value;
            currSize++;
            return true;
        }
        rear++;
        if(rear >= maxSize)
        {
            rear = 0;
        }
        queue[rear] = value;
        currSize++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(currSize == 0)
        {
            return false;
        }
        if(currSize == 1)
        {
            currSize = 0;
            return true;
        }
        front++;
        if(front>=maxSize)
        {
            front = 0;
        }
        currSize--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(currSize == 0)
        {
            return -1;
        }
        return queue[front];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(currSize == 0)
        {
            return -1;
        }
        return queue[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return currSize == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
