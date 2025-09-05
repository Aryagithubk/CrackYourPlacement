class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0, left = 0, right = 0, zeros = 0;
        int n = nums.size();

        while(right < n){
            
            if(nums[right] == 0)zeros++;
             

            if(zeros > k){
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