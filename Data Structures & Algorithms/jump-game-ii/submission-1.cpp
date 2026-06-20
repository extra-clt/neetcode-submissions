class Solution {
public:
    int jump(vector<int>& nums) {
        int maxLen = nums[0], maxIdx = 0, i = 1,cnt = 0, windmaxIdx = 0;
        while (i < nums.size()) {
            maxLen--;
            if (i == nums.size()-1) {
                cnt++;
                return cnt;
            }
            if (nums[i]+i > nums[maxIdx]+maxIdx) maxIdx = i;
            if (maxLen == 0) {
                //if maxIdx didnt change use last element of curr window
                if (maxIdx == windmaxIdx) i = maxIdx+nums[maxIdx];
                else i = maxIdx;
                windmaxIdx = maxIdx;
                maxLen = nums[maxIdx];
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};
