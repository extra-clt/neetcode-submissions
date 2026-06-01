class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, cost = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            profit = max(prices[i]-cost, profit);
            cost = min(prices[i], cost);
        }
        return profit;
    }
};
