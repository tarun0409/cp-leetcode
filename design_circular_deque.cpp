class MyCircularDeque {
public:
    int maxSize;
    int currSize;
    int * deque;
    int front;
    int rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxSize = k;
        currSize = 0;
        deque = (int *)calloc(k,sizeof(int));
        front = 0;
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(currSize == maxSize)
        {
            return false;
        }
        if(currSize == 0)
        {
            deque[front] = value;
            currSize++;
            return true;
        }
        front--;
        if(front<0)
        {
            front+=maxSize;
        }
        deque[front] = value;
        currSize++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(currSize == maxSize)
        {
            return false;
        }
        if(currSize == 0)
        {
            deque[rear] = value;
            currSize++;
            return true;
        }
        rear++;
        if(rear >= maxSize)
        {
            rear = 0;
        }
        deque[rear] = value;
        currSize++;
        return true;
        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
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
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(currSize == 0)
        {
            return false;
        }
        if(currSize == 1)
        {
            currSize = 0;
            return true;
        }
        rear--;
        if(rear<0)
        {
            rear = rear+maxSize;
        }
        currSize--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(currSize == 0)
        {
            return -1;
        }
        return deque[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(currSize == 0)
        {
            return -1;
        }
        return deque[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return currSize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
