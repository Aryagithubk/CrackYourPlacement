class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
      vector<int>dp(n,-1);
      vector<int>prev(n,-1);
      int maxi = 0;

      sort(nums.begin(),nums.end());

      for(int i=1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] % nums[j] == 0){
                if(dp[i] < (dp[j] + 1)){
                    dp[i] = dp[j]  + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[maxi]){
                maxi = i;
            }
        }
      }

      vector<int>v;
      while(maxi != -1){
        v.push_back(nums[maxi]);
        maxi = prev[maxi];
      }

      reverse(v.begin(),v.end());
      return v;

    }
};