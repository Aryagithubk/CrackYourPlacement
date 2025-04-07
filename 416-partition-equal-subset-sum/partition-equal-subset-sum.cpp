class Solution {
public:
    bool helper(vector<int>&nums,int sum,int ind,vector<vector<int>>&dp){
        if(sum == 0){
            return true;
        }

        if(ind == 0){
            return nums[ind] == sum;
        }

        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }

        //not taken
        bool nottaken = helper(nums,sum,ind-1,dp);

        //taken
        bool taken = false;
        if(nums[ind] <= sum){
            taken = helper(nums,sum-nums[ind],ind-1,dp);
        }

        return dp[ind][sum] = nottaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);

        if(totalsum% 2 != 0){
            return false;
        }else{
            int sum = totalsum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));//memory leak se bachne ke liye, k+1 kyuki size 0 se k tk hai mtlb size huya k+1
            return helper(nums,sum,n-1,dp);
        }

    }
};