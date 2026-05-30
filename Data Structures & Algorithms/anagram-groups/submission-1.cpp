class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            string res, word = strs[i];
            vector<int> cnt(26,0);
            for (char c : word) cnt[c-'a']++;
            for (int k : cnt) res += to_string(k) + ",";
            ans[res].push_back(word);
        }
        vector<vector<string>> sol;
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            vector<string> tmp = it->second;
            sol.push_back(tmp);
        }
        return sol;
    }
};
