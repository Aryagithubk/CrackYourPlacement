class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        if(n == 1){
            return nums[0];
        }

        if(nums[low] < nums[high]){
            return nums[low];
        }

        if(nums[high] < nums[high-1]){
            return nums[high];
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            if(mid > 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }//current element chota h pichle wale se means curr element is min element

            if(mid < n-1 && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }//curr element bda h next wale se means next element is min element

            if(nums[mid] > nums[0]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return nums[low];
    }
};