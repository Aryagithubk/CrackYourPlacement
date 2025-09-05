class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0, left=0,right=0;
        

        int n = nums.size();
            int zeros = 0;
        while(right < n){
            if(nums[right] == 0)zeros++;
            while(zeros > k){
                if(nums[left] == 0)zeros--;
                left++;
            }

            if(zeros <= k){
                maxi = max(maxi,(right-left+1));
            }

            right++;

        }

        return maxi;
    }
};