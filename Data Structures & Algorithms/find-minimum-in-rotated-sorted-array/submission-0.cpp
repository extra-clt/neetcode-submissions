class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] <= nums[nums.size()-1]) return nums[0];
        int l = 0, h = nums.size()-1;
        while (l < h) {
            int m = l + (h-l)/2;
            if (nums[l]>nums[h]) {
                if (nums[m] >= nums[l]) {
                    l = m+1;
                }
                else {
                    h = m;
                }
            }
            else {
                h=l;
            }
        }
        return nums[h];

    }
};
