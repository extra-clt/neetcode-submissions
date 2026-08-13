class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string sol;
        while (i < n && j < m) {
            sol += word1[i];
            sol += word2[j];
            i++, j++;
        }
        if (j < n) sol += word2.substr(j,n-j);
        if (i < m) sol += word1.substr(i,m-i);
        return sol;
    }
};