class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> tmp = triangle;
        for (int i = 1; i < tmp.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) tmp[i][j] += tmp[i-1][0];
                else if (j == i) tmp[i][j] += tmp[i-1][j-1];
                else tmp[i][j] += min(tmp[i-1][j-1], tmp[i-1][j]);
            }
        }
        return *min_element(tmp[(int)tmp.size()-1].begin(), tmp[(int)tmp.size()-1].end());
    }
};