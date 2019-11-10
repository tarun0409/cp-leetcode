class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> temp;
        int tempVal = 0;
        bool startVal = true;
        while(!q.empty())
        {
            if(!startVal)
            {
                temp.push(tempVal);
            }
            else
            {
                startVal = false;
            }
            tempVal = q.front();
            q.pop();
        }
        q.swap(temp);
        return tempVal;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
