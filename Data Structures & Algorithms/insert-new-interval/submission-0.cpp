class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //overlap mech: max(s1,s2) <= min(e1,e2)
        //if not overlap push the smallest to output (based on start)-it is sorted
        //if overlap, newInterval-> s = min(both), e = max(both);
        vector<vector<int>> sol;
        for (int i = 0; i < intervals.size(); i++) {
            if (max(newInterval[0],intervals[i][0]) <= min(newInterval[1],intervals[i][1])) {//overlap
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
            else {
                if (newInterval[0] < intervals[i][0]) {
                    sol.push_back(newInterval);
                    newInterval = intervals[i];
                }
                else sol.push_back(intervals[i]);
            }
        }
        sol.push_back(newInterval);
        return sol;
    }
};

