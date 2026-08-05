class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sm = nums[0], ans = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) sm += nums[i];
            else {
                ans = max(ans,sm);
                sm = nums[i];
            }
        }
        return max(ans,sm);

    }
};