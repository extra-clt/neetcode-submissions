class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int prevEnd = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (prevEnd <= intervals[i][0]) {
                prevEnd = intervals[i][1];
                cnt++;
            }
            //else overlap happens
            //remove intervals[i]-we keep early endings only = prevEnd
            //no. of distinct prevEnd only gets throguh.
        }
        return int(intervals.size())-cnt;
    }
};
