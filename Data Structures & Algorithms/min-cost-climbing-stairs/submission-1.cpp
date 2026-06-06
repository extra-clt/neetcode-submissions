class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0, prev1 = 0;
        for (int i = 1; i < cost.size(); i++) {
            int tmp = min(prev2+cost[i-1],prev1+cost[i]);
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};
