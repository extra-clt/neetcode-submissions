class MinStack {
public:
    MinStack() {
        
    }

    stack<int> s,st;
    int minVal = INT_MAX;
    
    void push(int val) {
        minVal = min(val, minVal);
        st.push(minVal);
        s.push(val);
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            s.pop();
            if (!st.empty()) minVal = st.top();
            else minVal = INT_MAX;
        }
    }
    
    int top() {
        if (!s.empty()) return s.top();
    }
    
    int getMin() {
        if (!st.empty()) return st.top();
    }
};
