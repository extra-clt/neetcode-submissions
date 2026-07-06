class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sol = INT_MIN, minpdt = 1, maxpdt = 1;
        for (int i = 0; i < nums.size(); i++) {
            int tmpmin = minpdt;
            minpdt = min(min(nums[i], minpdt*nums[i]), maxpdt*nums[i]);
            maxpdt = max(max(nums[i], tmpmin*nums[i]), maxpdt*nums[i]);
            sol = max(sol, maxpdt);
        }
        return sol;

      




    }
};
