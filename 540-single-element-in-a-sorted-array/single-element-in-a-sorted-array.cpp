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
        if(nums[0] != nums[1]){
            return nums[0];
        }

       int low = 1;
       int high = n-2;

       while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        if(mid%2 != 0 and nums[mid] == nums[mid+1]){
            high = mid-1;
        }
        else if(mid%2 == 0 and nums[mid] == nums[mid-1]){
            high = mid-1;
        }else{
            low = mid+1;
        }
     }

        return ans;
    }
};