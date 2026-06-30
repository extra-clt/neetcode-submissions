class Solution {
public:
    bool palindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    vector<string> sub(int start, string s) {
        vector<string> sol;
        for (int end = start; end < s.size(); end++) {
            string str = s.substr(start, end-start+1);
            sol.push_back(str);
        }
        return sol;
    }
    vector<string> path;
    vector<vector<string>> ans;
    void dfs(vector<string> &forms, string &s) {
        if (forms.empty()) {
            ans.push_back(path);
            return;
        }
        for (string a : forms) {
            if (!palindrome(a)) continue;
            int len = a.size(); //i need to start from idx=len
            path.push_back(a);
            string new_s = s.substr(len,s.size()-1);
            vector<string> newforms = sub(0,new_s);
            //cout << "a: " << a << " ";
            //cout << "len: " << len << " new_s: " << new_s <<endl;
            //for (string w : newforms) cout << w << " ";
            //cout << endl;
            dfs(newforms,new_s);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        //source: starting letter=s[0], then n variations (len=1,2...n)
        vector<string> forms = sub(0,s);
        //for (string s : forms) cout << s << " ";
        dfs(forms,s);
        return ans;
    }
};
