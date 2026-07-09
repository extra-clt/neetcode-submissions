class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> sol = {1};
        vector<vector<int>> ans = {{1}};
        for (int j = 2; j <= n; j++) {
            vector<int> tmp;
            for (int i = 0; i < j; i++) {
                if (i == 0 || i == j-1) tmp.push_back(1);
                else tmp.push_back(sol[i-1]+sol[i]);
            }
            ans.push_back(tmp);
            sol = tmp;
        }
        return ans;
    }
};