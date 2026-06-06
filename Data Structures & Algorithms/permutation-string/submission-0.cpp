class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> us1, us2;
        int n = s1.size();
        int cnt = 0;
        for (char &i : s1) us1[i]++;
        for (int i = 0; i < n; i++) us2[s2[i]]++;
        for (int i = 0; i < n; i++) {
            if (us1[s2[i]] != us2[s2[i]]) {
                break;
            }
            else cnt++;
        }
        if (cnt == n) return true;
        for (int i = n; i < s2.size(); i++) {
            cnt = 0;
            us2[s2[i]]++;
            us2[s2[i-n]]--;
            for (int k = i-n+1; k <= i; k++) {
                if (us1[s2[k]] != us2[s2[k]]) {
                    break;
                }
                else cnt++;
            }
            if (cnt == n) return true;
        }
        return false;
    }
};
