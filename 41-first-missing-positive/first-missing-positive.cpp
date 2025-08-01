class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            while(nums[i] > 0 and nums[i] < n and nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1],nums[i]);
                
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
        

    }
};