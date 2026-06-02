class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (!st.empty()) {
                char a = st.top();
                char b = s[i];
                if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) st.pop();
                else st.push(b);
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};
