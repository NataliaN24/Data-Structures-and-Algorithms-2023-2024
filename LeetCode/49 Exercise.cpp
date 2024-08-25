class MyStack {

    queue<int>q1;
    queue<int>q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int topEl=q1.front();
        q1.pop();
        return topEl;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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
-------------------------------------------------------ANOTHER SOLUTION--------------------------------------------------------------------------------------------
    class MyStack {

   deque<int>dq;

public:
    MyStack() {
        
    }
    
    void push(int x) {
       dq.push_back(x);
    }
    
    int pop() {
        int topEl=dq.back();
        dq.pop_back();
        return topEl;
    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return dq.empty();
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
