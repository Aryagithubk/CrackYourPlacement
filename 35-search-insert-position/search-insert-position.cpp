class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int s = 0;
        int e = n-1;

        while(s <= e){
            int m = s + (e-s)/2;
            if(target == nums[m]){
                return m;
            }else if(target < nums[m]){
                e = m-1;
            }else{
                s = m+1;
                ans = s;
            }
        }
        return ans;
    }

};