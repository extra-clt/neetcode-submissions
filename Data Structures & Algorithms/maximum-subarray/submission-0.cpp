class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            curr = max(curr+nums[i], nums[i]);
            maxVal = max(curr,maxVal);
        }
        return maxVal;
    }
};
