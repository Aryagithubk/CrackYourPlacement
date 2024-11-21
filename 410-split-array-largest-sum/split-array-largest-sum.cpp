class Solution {
public:

    int fxn(vector<int>&nums,int val){
        int n = nums.size();
        int arr = 0;
        int value = 0;

        for(int i=0; i<n; i++){
            if(value + nums[i] <= val){
                value += nums[i];
            }else{
                arr++;
                value = nums[i];
            }
        }
        return arr;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(fxn(nums,mid) >= k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low;
    }
};