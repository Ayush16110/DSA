class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int value) {
        if(this->s.empty()) {
            this->s.push({value, value});
        } else {
            this->s.push({value, min(value, s.top().second)});
        }
    }
    
    void pop() {
        this->s.pop();
    }
    
    int top() {
        return this->s.top().first;
    }
    
    int getMin() {
        return this->s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */