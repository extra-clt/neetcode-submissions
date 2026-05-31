class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = 0, idx = -1, pdt = 1, n = nums.size();
        vector<int> sol(n,0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCnt++;
                idx = i;
            }
            else {
                pdt *= nums[i];
            }
        }
        if (zeroCnt == 1) {
            sol[idx] = pdt;
            return sol;
        }
        if (zeroCnt > 1) {
            return sol;
        }
        for (int i = 0; i < n; i++) {
            sol[i] = pdt/nums[i];
        }
        return sol;
    }
};
