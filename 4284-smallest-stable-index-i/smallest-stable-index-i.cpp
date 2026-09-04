class Solution {
public:

    int fxn1(vector<int>&nums, int ind){
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i=0; i<=ind; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        return maxi;
    }

    int fxn2(vector<int>&nums, int ind){
        int n = nums.size();
        int mini = INT_MAX;

        for (int i=ind; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        return mini;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        
        int ans = -1;

        for(int i=0; i<nums.size(); i++){
            int stable = 0;

            int maxi = fxn1(nums,i);
            int mini = fxn2(nums,i);

            stable = maxi - mini;

            if(stable <= k){
                ans = i;
                break;
            }
        }

        return ans;
    }
};