class Solution {
public:
    vector<int> partitionLabels(string s) {
        //first and last occurence of an element must be in the substring
        //so first find all final occur and stor ein vector of size 26
        //i moves from 0 to max last occur of elem in substring
        //if i == max last occur index, then thats a substring and i++ and move on
        vector<int> lastOccur(26,-1), sol;
        for (int i = 0; i < s.size(); i++) {
            lastOccur[s[i]-'a'] = i;
        }
        int end = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end,lastOccur[s[i]-'a']);
            cnt++;
            if (i == end) {
                sol.push_back(cnt);
                cnt = 0;
                end = 0;
            }
        }
        return sol;
    }
};
