class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        if(n == 1){
            return 0;
        }

        if(nums[left] > nums[left+1]){
            return left;
        }

        if(nums[right] > nums[right-1]){
            return right;
        }



        while(left <= right){
            int mid = left + (right-left)/2;
            if(mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            if(mid > 0 && nums[mid] > nums[mid-1]){
                left = mid + 1;
            }

            if(mid < n-1 && nums[mid] < nums[mid+1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return -1;
    }
};