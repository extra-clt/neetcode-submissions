class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol;
        for (int i = 0; i < n+1; i++) {
            int cnt = 0;
            int num = i;
            while (num>0) {
                if (num & 1) cnt++;
                num >>= 1;
            }
            sol.push_back(cnt);
        }
        return sol;
    }
};
