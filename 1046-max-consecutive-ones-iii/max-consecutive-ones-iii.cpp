class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0,zeros = 0;
        int maxi = INT_MIN;

        for(int right = 0; right<n; right++){
            if(nums[right] == 0) zeros++;

            if(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }

            maxi = max(maxi,right-left+1);

        }

        return maxi;

    }
};