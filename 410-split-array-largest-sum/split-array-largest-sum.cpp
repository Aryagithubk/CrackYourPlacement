class Solution {
public:
    int helper(vector<int>&nums, int val){
        int count = 0;
        int value = 0;
        for(int i=0; i<nums.size(); i++){
            if(value + nums[i] <= val){
                value += nums[i];
            }else{
                count++;
                value = nums[i];
            }
        }

        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);

        while(left <= right){
            int mid = left + (right - left)/2;

            if(helper(nums,mid) >= k){//means mid ka value chota hai jisse jyada split ho re 
                left = mid+1;//mid ka value bdha denge
            }else{
                right = mid-1;//mid ka value ghata denge
            }
        }

        return left;
    }
};