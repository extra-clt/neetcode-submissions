class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while (n != 1) {
            string s = to_string(n);
            int res = 0;
            for (char c : s) {
                int val = c-'0';
                res += val*val;
            }
            if (us.count(res)) return false;
            us.insert(res);
            n = res;
        }
        return true;
    }
};
