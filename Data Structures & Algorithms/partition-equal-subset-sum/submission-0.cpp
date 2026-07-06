class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (n == 1 && nums[0] == 0) return true;
        if (target & 1 || n == 1) return false;
        target >>= 1;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        int lim = 0;
        for (int i : nums) {
            vector<bool> tmp = dp;
            int idx = 0;
            for (int j = 0; j <= lim; j++) {
                if (dp[j] && i+j <= target) {
                    tmp[i+j] = true;
                    idx = i+j;
                    if (i+j == target) return true;
                }
            }
            dp = tmp;
            lim = idx;
        }
        return false;
    }
};
