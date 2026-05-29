class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> um;
        for (char a : s) um[a]++;
        for (char b : t) um[b]--;
        for (char a : s) {
            if (um[a] != 0) return false;
        }
        return true;
    }
};
