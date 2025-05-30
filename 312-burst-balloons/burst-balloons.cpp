class Solution {
public:
    int helper(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long maxi = LLONG_MIN;

        for(long long k=i; k<=j; k++){
            long long coins = nums[i-1] * nums[k] * nums[j+1];
            long long rem_coins = helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
            maxi = max(maxi,coins+rem_coins);
        }

        return dp[i][j] = (int)maxi;

    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

        return helper(1,n,nums,dp);//as at position 0 and n+1 there is virtual 1 present which is not ballon but inserted just for calculation.
    }
};