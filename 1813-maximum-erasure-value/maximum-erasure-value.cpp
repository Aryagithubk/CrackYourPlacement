class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>mp;

        int maxi_sum = INT_MIN;

       int i = 0;
       int j=0;
        int sum = 0;
       while(i < nums.size()){
            while(mp.find(nums[i]) != mp.end()){
                mp.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
                mp.insert(nums[i]);
                sum += nums[i];
            maxi_sum = max(maxi_sum,sum);
                i++;          
       }

       return maxi_sum;
    }
};