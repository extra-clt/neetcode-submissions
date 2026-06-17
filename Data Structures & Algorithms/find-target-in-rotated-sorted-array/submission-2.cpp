class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] <= nums[nums.size()-1]) return 0;
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
        return h;
    }
    int bs(vector<int>& nums, int target, int low, int high) {
        int l = low, h = high;
        while (l <= h) {
            int m = l + (h-l)/2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) h = m-1;
            else l = m+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int idx = findMin(nums);
        if (nums[idx] == target) return idx;
        idx = bs(nums,target,0,idx-1);
        if (idx != -1) return idx;
        int n = nums.size();
        idx = bs(nums,target,idx+1,n-1);
        if (idx != -1) return idx;
        return -1;
    }
};
