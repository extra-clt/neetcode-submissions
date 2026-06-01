class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size() - 2; k++) {
            int i = k+1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] > -nums[k]) j--;
                else if (nums[i] + nums[j] < -nums[k]) i++;
                else {
                    sol.push_back({nums[k],nums[i],nums[j]});
                    i++; j--;
                };
            }
        } 
        set<vector<int>> us(sol.begin(), sol.end());
        vector<vector<int>> ans(us.begin(), us.end());
        return ans;
    }
};
