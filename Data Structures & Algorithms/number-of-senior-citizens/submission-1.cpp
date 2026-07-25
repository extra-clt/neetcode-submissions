class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (string s : details) {
            int num = stoi(s.substr(11,2));
            if (num > 60) cnt++;
        }
        return cnt;
    }
};