class Solution {
public:
    bool helper(vector<int>&nums,int p,int mid){
        int count = 0;
        int i = 1;
        int n = nums.size();

        while(i < n){
            if((nums[i] - nums[i-1]) <= mid){
                count++;
                i += 2;
            }else{
                i++;
            }
             
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int low = 0, high = nums.back() - nums[0];
       int ans = high;//by default max diff would be high


       while(low <= high){
            int mid = low + (high - low)/2;

            if(helper(nums,p,mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
       }

       return ans;
    }
};