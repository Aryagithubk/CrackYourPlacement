class MyQueue {
private:
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
       if(st2.empty()){

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

       } 
       if(!st2.empty()){
            int top1 = st2.top();
            st2.pop();
            return top1;
       }

       return -1;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        if(!st2.empty()){
            return st2.top();
        }
        return -1;
    }
    
    bool empty() {
        return st1.empty() and st2.empty();
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