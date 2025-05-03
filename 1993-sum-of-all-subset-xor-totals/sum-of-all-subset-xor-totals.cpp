class Solution {
public:
    int fxn(vector<int>&nums,int sum,int ind){
        if(ind == nums.size()){
            return sum; 
        }

        //not pick
        int x = fxn(nums,sum,ind+1);
        //pick
        sum = sum ^ nums[ind];
        int y = fxn(nums,sum,ind+1);

        return x+y;
    }
    int subsetXORSum(vector<int>& nums) {
        
        return fxn(nums,0,0);

            
    }
};