class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = 0;          // Index of the minimum buying price
        int maxProfit = 0;    // Maximum profit found so far

        for (int sell = 1; sell < prices.size(); sell++) {

            // Found a better (lower) buying price
            if (prices[sell] < prices[buy]) {
                buy = sell;
            }

            // Calculate profit if we sell today
            int profit = prices[sell] - prices[buy];

            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};