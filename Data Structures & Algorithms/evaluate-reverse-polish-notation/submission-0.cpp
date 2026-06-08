class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string &c : tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/") s.push(stoi(c));
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (c == "+") s.push(a+b);
                else if (c == "-") s.push(a-b);
                else if (c == "*") s.push(a*b);
                else if (b == 0) s.push(INT_MIN);
                else s.push(a/b);
            }
        }
        return s.top();
    }
};
