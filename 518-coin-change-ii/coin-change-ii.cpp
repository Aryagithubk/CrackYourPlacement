class Solution {
public:
    int fxn(int amount,vector<int>&coins,int index,vector<vector<int>>&dp){
        int n = coins.size();
        if(index >= n){
            return 0;
        }
        if(amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }

        if(dp[amount][index] != -1){
            return dp[amount][index];
        }

        int w1 = fxn(amount - coins[index],coins,index,dp);//pick krenge coin ko
        int w2 = fxn(amount,coins,index+1,dp); //not pick bs aage bdhenge next coin

        return dp[amount][index] =  w1 + w2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount + 1,vector<int>(coins.size(),-1));
        return fxn(amount,coins,0,dp);
    }
};