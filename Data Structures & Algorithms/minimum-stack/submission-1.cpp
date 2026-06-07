class MinStack {
public:
    MinStack() {
        
    }

    vector<int> st;
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if (!st.empty()) st.pop_back();
    }
    
    int top() {
        if (!st.empty()) return st[st.size()-1];
    }
    
    int getMin() {
        if (!st.empty()) return *min_element(st.begin(), st.end());
    }
};
