class MinStack {
    stack<int> s;
    stack<int> mn;

public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);

        if (mn.empty() || val <= mn.top()) {
            mn.push(val);
        }
    }
    
    void pop() {
        if (s.top() == mn.top()) {
            mn.pop();
        }

        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};