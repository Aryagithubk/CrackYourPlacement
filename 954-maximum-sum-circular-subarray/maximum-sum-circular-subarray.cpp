class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = 0;
        int mini = 0;
        int track_maxi = INT_MIN;
        int track_mini = INT_MAX;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            maxi = max(nums[i],maxi+nums[i]);
            track_maxi = max(track_maxi,maxi);

            mini = min(nums[i],mini+nums[i]);
            track_mini = min(track_mini,mini);

        }

        if(track_maxi < 0){
            return track_maxi;
        }

        return max(track_maxi,sum-track_mini);
    }
};