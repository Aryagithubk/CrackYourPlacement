class Solution {
public:
    int helper(vector<int>&prices,int ind,int buy,int n,vector<vector<int>>&dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        int max_profit = 0;

        if(buy == 0){//buying
            max_profit = max(0 + helper(prices,ind+1,0,n,dp),-prices[ind] + helper(prices,ind+1,1,n,dp));
        }

        if(buy == 1){//selling
            max_profit = max(0 + helper(prices,ind+1,1,n,dp), prices[ind] + helper(prices,ind+1,0,n,dp));
        }

        return dp[ind][buy] = max_profit;


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return helper(prices,0,0,n,dp);
    }
};