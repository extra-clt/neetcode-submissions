class Solution {
public:
    int numDecodings(string s) {
        vector<int> freq(s.size(), -1);
        return backtrack(0, s, freq);
    }
    int backtrack(int start, string &s, vector<int> &freq) {
        if (start == s.size()) return 1;
        if (s[start] == '0') return 0;
        if (freq[start] != -1) return freq[start];
        int tot = 0;
        for (int end = start + 1; end <= s.size(); end++) {
            string curr = s.substr(start, end - start);
            if (curr.size() <= 2 && 1 <= stoi(curr) && stoi(curr) <= 26) {
                tot += backtrack(end, s, freq);
            }
        }
        return freq[start] = tot;
    }
};