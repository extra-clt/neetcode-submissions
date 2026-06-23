class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];//curr is always highest
        vector<vector<int>> sol;
        for (int i = 1; i < intervals.size(); i++) {
            if (max(curr[0],intervals[i][0]) <= min(curr[1],intervals[i][1])) {//overlap
                curr[0] = min(curr[0], intervals[i][0]);
                curr[1] = max(curr[1], intervals[i][1]);
            }
            else {
                if (curr[0] < intervals[i][0]) {
                    sol.push_back(curr);
                    curr = intervals[i];
                }
                else sol.push_back(intervals[i]);
            }
        }
        sol.push_back(curr);
        return sol;
    }
};
