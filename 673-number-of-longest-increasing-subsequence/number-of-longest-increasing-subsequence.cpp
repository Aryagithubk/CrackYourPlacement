class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,1);
        vector<int>ct(n,1);

        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev] < nums[i] and dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    ct[i] = ct[prev];
                }else if(nums[prev] < nums[i] and dp[prev]+1 == dp[i]){
                    ct[i] += ct[prev];
                }
            }

            maxi = max(maxi,dp[i]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi){
                count += ct[i];
            }
        }

        return count;

    }
};