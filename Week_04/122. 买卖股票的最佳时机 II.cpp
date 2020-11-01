class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2] = {0, -prices[0]};
        for (int i = 1; i < prices.size(); i++) {
            int tmp_dp[2] = {0, 0};
            tmp_dp[0] = max(dp[0], dp[1] + prices[i]);
            tmp_dp[1] = max(dp[1], dp[0] - prices[i]); 
            dp[0] = tmp_dp[0];
            dp[1] = tmp_dp[1];
        }
        return dp[0];
    }
};
