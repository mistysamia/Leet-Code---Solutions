class MinStack {
public:
    deque<int>deq;
    MinStack() {
        deq.clear();
    }
    
    void push(int val) {
        deq.push_back(val);
    }
    
    void pop() {
        deq.pop_back();
    }
    
    int top() {
      return deq.back();
    }
    
    int getMin() {
        return *min_element(deq.begin(), deq.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
