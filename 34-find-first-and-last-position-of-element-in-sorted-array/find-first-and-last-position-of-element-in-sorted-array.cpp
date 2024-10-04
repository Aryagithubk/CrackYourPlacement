class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e = n-1;

        int x = -1,y=-1;

        while(s <= e){
            int m = s + (e-s)/2;
            if(target == nums[m]){
                x = m;
                e = m-1;
            }else if(target < nums[m]){
                e = m-1;
            }else{
                s = m+1;
            }
        }

        s = 0,e = n-1;

        while(s <= e){
            int m = s + (e-s)/2;
            if(target == nums[m]){
                y = m;
                s = m+1;
            }else if(target < nums[m]){
                e = m-1;
            }else{
                s = m+1;
            }
        }

        return {x,y};
    }
};