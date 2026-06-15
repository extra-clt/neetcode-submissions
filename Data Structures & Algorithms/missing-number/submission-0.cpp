class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sol = nums[0], n = nums.size();
        sol ^= n;
        sol ^= 0;
        for (int i = 1; i < n; i++) {
            sol ^= nums[i];
            sol ^= i;
        }
        return sol;
    }
};
