class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 1;
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[even] = nums[i];
                even += 2;
            }else if(nums[i] < 0){
                ans[odd] = nums[i];
                odd += 2;
            }
        }

        return ans;
    }
};