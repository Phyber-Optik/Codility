class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>left;
    stack<int>right;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        left.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(right.empty()) {
            while(!left.empty()) {
                int top = left.top();
                right.push(top);
                left.pop();
            }
        }
        int ret = right.top();
        right.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(right.empty()) {
            while(!left.empty()) {
                int top = left.top();
                right.push(top);
                left.pop();
            }
        }
        int ret = right.top();
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return left.empty() && right.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */