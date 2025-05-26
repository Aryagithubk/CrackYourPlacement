class Solution {
public:
    const int mod = (int)1e9 + 7;
    int helper(vector<int>&nums, int target){
        int n = nums.size();
         vector<int>prev(target + 1,0);

        if(nums[0] == 0){
            prev[0] = 2;
        }
        else{
            prev[0] = 1;
        }
        if(nums[0] != 0 and nums[0] <= target){
            prev[nums[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            vector<int>curr(target+1,0);
            for(int tar = 0; tar <= target; tar++){
                int nottaken = prev[tar];

                int taken = 0;
                if(nums[ind] <= tar){
                    taken = prev[tar - nums[ind]];
                }

                curr[tar] = (nottaken + taken) % mod;
            }

            prev = curr;
        }

        return prev[target];

    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //1st eqn -> s1 - s2 = target
        //2nd eqn -> s1 + s2 = totalsum
        // s2 = (totalsum - target)/2
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if(sum - target < 0 || (sum - target)% 2 != 0){
            return 0;
        }

        int s2 = (sum - target)/2;

        return helper(nums,s2);
    }
       
};