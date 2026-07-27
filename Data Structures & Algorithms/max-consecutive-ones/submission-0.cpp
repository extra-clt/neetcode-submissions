class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxcnt = 0;
        for (int i : nums) {
            if (i == 1) cnt++;
            else {
                maxcnt = max(cnt,maxcnt);
                cnt = 0;
            }
        }
        return max(cnt, maxcnt);
    }
};