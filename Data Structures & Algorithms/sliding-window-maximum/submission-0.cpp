class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> sol;
        for (int i = 0; i < nums.size()-k+1; i++) {
            int maxVal = INT_MIN;
            for (int j = i; j < i+k; j++) {
                maxVal = max(maxVal,nums[j]);
            }
            sol.push_back(maxVal);
        }
        return sol;
    }
};
