class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
         const long long NEG = -1e18;
        int n = prices.size();

        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;
        dp[0][1] = -prices[0]; // buy
        dp[0][2] = prices[0];  // short sell

        for (int i = 1; i < n; i++) {
            vector<vector<long long>> newdp = dp;

            for (int t = 0; t <= k; t++) {
                // start transactions
                newdp[t][1] = max(newdp[t][1], dp[t][0] - prices[i]);
                newdp[t][2] = max(newdp[t][2], dp[t][0] + prices[i]);

                // close transactions
                if (t + 1 <= k) {
                    newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][1] + prices[i]);
                    newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][2] - prices[i]);
                }
            }
            dp = newdp;
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = max(ans, dp[t][0]);
        }
        return ans;
    }
};