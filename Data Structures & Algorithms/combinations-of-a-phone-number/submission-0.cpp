class Solution {
public:
    vector<vector<string>> phone = {{""},{""},{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
    vector<string> mul(vector<string> &a, vector<string> &b) {
        vector<string> sol;
        for (int i = 0; i < a.size(); i++) {
            string base = a[i];
            for (int j = 0; j < b.size(); j++) {
                string tmp = base + b[j];
                sol.push_back(tmp);
            }
        }
        return sol;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        if (n == 1) return phone[digits[0]-'0'];
        vector<string> a = phone[digits[0]-'0'], b, tmp;
        for (int i = 1; i < n; i++) {
            b = phone[digits[i]-'0'];
            tmp = mul(a,b);
            a = tmp;
        }
        return a;
    }
};
