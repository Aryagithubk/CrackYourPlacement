class Solution {
public:
    bool helper(vector<int>&nums,int targetSum,int ind,vector<vector<int>>&dp){
        if(targetSum == 0){
            return true;
        }

        if(ind == 0){
            return (nums[0] == targetSum);
        }

        if(dp[ind][targetSum] != -1){
            return dp[ind][targetSum];
        }

        bool notTaken = helper(nums,targetSum,ind-1,dp);

        bool taken = false;
        if(nums[ind] <= targetSum){
            taken = helper(nums,targetSum-nums[ind],ind-1,dp);
        }

        return dp[ind][targetSum] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0){
            return false;
        }else{
            int k = totalSum/2;

        vector<vector<int>>dp(n,vector<int>(k+1,-1));
            return helper(nums,k,n-1,dp);
        }
    }
};