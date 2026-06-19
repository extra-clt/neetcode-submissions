class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetIdx = nums.size()-1;
        for (int i = nums.size()-2; i >= 0; i--) if (targetIdx-i <= nums[i]) targetIdx = i;
        return (!targetIdx);
    }
};
