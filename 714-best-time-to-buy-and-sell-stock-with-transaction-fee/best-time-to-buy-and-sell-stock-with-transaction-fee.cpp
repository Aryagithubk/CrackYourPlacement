class Solution {
public:
    int helper(int ind, int buy, int n, int fee, vector<int>&prices, vector<vector<int>>&dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if(buy == 0){
            profit = max(0 + helper(ind+1,0,n,fee,prices,dp), -prices[ind] + helper(ind+1,1,n,fee,prices,dp));
        }
        if(buy == 1){
            profit = max(0 + helper(ind+1,1,n,fee,prices,dp) , prices[ind] - fee + helper(ind+1,0,n,fee,prices,dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));

        return helper(0,0,n,fee,prices,dp);
    }
};