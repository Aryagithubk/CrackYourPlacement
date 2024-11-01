class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }

        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        for(int i=0; i<n-1; i+=2){
            if(nums[i] != nums[i+1]){
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};