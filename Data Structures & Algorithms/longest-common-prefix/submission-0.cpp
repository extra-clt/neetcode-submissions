class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(); 
        int len = INT_MAX;
        string sol = "";
        for (int i = 0; i < n; i++) {
            len = min((int)strs[i].size(),len);
        }
        for (int i = 0; i < len; i++) {//till min letter in a string
            int letter = strs[0][i];
            for (int j = 0; j < n; j++) {
                if (strs[j][i] != letter) return sol;
            }
            sol += letter;
        }
        return sol;
    }
};