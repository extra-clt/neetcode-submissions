class Solution {
public:

    string encode(vector<string>& strs) {
        string sol;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            int len = word.size();
            string res = to_string(len) + "+" + word;
            sol += res;
        }
        return sol;
    }

    vector<string> decode(string s) {
        vector<string> sol;
        int i = 0;
        while (i < s.size()) {
            string lenStr;
            while (s[i] != '+') {
                lenStr += s[i];
                i++;
            }
            int len = stoi(lenStr);
            string word;
            for (int k = i+1; k < i+1+len; k++) {
                word += s[k];
            }
            i += len + 1;
            sol.push_back(word);
        }
        return sol;
    }
};
