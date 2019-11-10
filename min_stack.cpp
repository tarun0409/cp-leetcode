class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> s;
    MinStack() {
        
    }
    
    void push(int x) {
        s.insert(s.begin(),x);
    }
    
    void pop() {
        if(s.size() > 0)
        {
            s.erase(s.begin());
        }
    }
    
    int top() {
        if(s.size() > 0)
        {
            return s[0];   
        }
        return -1;
    }
    
    int getMin() {
        int minElement = INT_MAX;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] < minElement) minElement = s[i];
        }
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
