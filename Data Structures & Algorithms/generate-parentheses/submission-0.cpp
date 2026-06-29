class Solution {
public:
    string path;
    vector<string> sol;
    void bt(int sm1, int sm2, int n) {
        if (sm1 > n || sm2 > n || sm2 > sm1) return;
        if (sm1 == n && sm2 == n) {
            sol.push_back(path);
            return;
        }
        path.push_back('(');
        bt(sm1+1,sm2,n);
        path.pop_back();
        path.push_back(')');
        bt(sm1,sm2+1,n);
        path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        bt(0,0,n);
        return sol;
    }
};
