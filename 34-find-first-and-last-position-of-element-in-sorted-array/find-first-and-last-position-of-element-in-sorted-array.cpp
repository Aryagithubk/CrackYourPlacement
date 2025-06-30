class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size()-1;
        int i=  -1,j = -1;


        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target ){
               i = mid;
               end = mid-1;//lower bound kr re end ko aage le ja re taaki aur aage ka elements dekhe jo present ho , just way of finding very first index
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        start = 0,end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                j = mid;
                start = mid + 1;//start ko piche le jaa re taaki very last index khoj ske isiliye boundary aage se km kr re aur piche dekh re bs

            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return {i,j};

    }
};