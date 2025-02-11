class Solution {
public:
    int fxn(int ind,vector<int>&nums,vector<int>&dp){
        if(ind == 0){
            return nums[ind];
        }

        if(ind < 0){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        //pick
        int pick = nums[ind] + fxn(ind - 2,nums,dp);
        //not pick

        int notPick = 0 + fxn(ind-1,nums,dp);
        return dp[ind] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return fxn(n-1,nums,dp);
    }
};