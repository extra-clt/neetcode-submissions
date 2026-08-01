class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> um;
        for (string s : emails) {
            string sol;
            bool plus = false, at = false;
            for (char c : s) {
                if (c == '.' && !at) continue;
                if (c == '@') {at = true; plus = false;}
                if (c == '+' && !at) plus = true;
                if (plus) continue;
                sol += c;
            }
            um[sol]++;
        }
        for (auto x : um) {
            cout << x.first << " : " << x.second << endl;
        }
        return (int)um.size();
    }
};