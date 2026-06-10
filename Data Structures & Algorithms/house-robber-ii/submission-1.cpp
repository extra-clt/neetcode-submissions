class Solution {
public:
    int rob(vector<int>& nums) {
        //like house robber- but
        //Idea is first and last house cant be together. so exclusion tactic
        //split array into 0->n-2 and 1->n-1
        //find max of them
        if (nums.size() == 1) return nums[0];
        int prev1 = 0, prev2 = 0, sol1 = 0, sol2 = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            sol1 = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = sol1;
        }
        prev1 = 0, prev2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            sol2 = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = sol2;
        }
        return max(sol1, sol2);
    }
};
