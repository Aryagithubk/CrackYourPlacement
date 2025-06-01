class Solution {
public:
    int helper(vector<int>&prices,int n,int cap,int ind,int buy,vector<vector<vector<int>>>&dp){
        if(ind == n || cap == 0) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;

        if(buy == 0){
            profit = max(0 + helper(prices,n,cap,ind+1,0,dp), -prices[ind] + helper(prices,n,cap,ind+1,1,dp));
        }
        if(buy == 1){
            profit = max(0 + helper(prices,n,cap,ind+1,1,dp), prices[ind] + helper(prices,n,cap-1,ind+1,0,dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return helper(prices,n,k,0,0,dp);
    }
};