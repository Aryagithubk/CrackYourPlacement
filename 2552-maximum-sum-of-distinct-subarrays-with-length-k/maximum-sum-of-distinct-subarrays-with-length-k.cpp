class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        long long maxi = 0;
        long long sum = 0;
        long long n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            sum += nums[i];

            if(i >= k){
                int pos = i-k;
                mp[nums[pos]]--;
                sum -= nums[pos];

                if(mp[nums[pos]] == 0){
                    mp.erase(nums[pos]);
                }
            }
            if(i >= k-1 && mp.size() == k){
                maxi = max(maxi,sum);
            }

        }

        return maxi;
       


    }
};