class Solution {
public:
    int helper(vector<int>&nums,int sz,int ind,int prev,vector<vector<int>>&dp){
        if(ind == sz){
            return 0;
        }
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        int notTaken = helper(nums,sz,ind+1,prev,dp);
        int taken = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            taken = 1 + helper(nums,sz,ind+1,ind,dp);
        }

        return dp[ind][prev+1] = max(notTaken,taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(nums,n,0,-1,dp);
    }
};