class Solution {
public:
    int helper(vector<int>&nums,int start,int end,vector<int>&dp){
        if(start > end){
            return 0;
        }

        if(dp[start] != -1){
            return dp[start];
        }
        //pick
        int pick = nums[start] + helper(nums,start+2,end,dp);
        //not pick
        int notPick = 0 + helper(nums,start + 1,end,dp);
        return dp[start] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n == 1){
            return nums[0];
        }

        int case1 = helper(nums,0,n-2,dp1);
        int case2 = helper(nums,1,n-1,dp2);

        return max(case1,case2);
    }
};