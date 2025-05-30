class Solution {
public:
    int helper(int start,int end,vector<int>&arr,int k,vector<int>&dp){
        if(start == end){
            return 0;
        }

        if(dp[start] != -1) return dp[start];
        int len = 0;
        int largest_sum = INT_MIN;
        int maxi = INT_MIN;

        for(int i=start; i<min(end, start + k); i++){//You should try partitions of length 1 to k, starting at start, but only go as far as n (size of array).
        //n - k + 1 is used when you're sliding a window of size k across the array. But here, you're doing variable-length partitions from 1 to k, not a fixed-length sliding window.
            len++;
            maxi = max(maxi,arr[i]);
            int sum = maxi * len + helper(i+1,end,arr,k,dp);
            largest_sum = max(largest_sum,sum);
        }

        return dp[start] = largest_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n = arr.size();
       vector<int>dp(n,-1);

       return helper(0,n,arr,k,dp);

    }
};