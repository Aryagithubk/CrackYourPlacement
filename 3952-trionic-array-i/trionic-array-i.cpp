class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        if(n < 4) return false;

        int i = 0;

        while(i+1 < n and nums[i] < nums[i+1]){
            i++;
        }

        if(i == 0) return false;

        int p = i;

        while(i+1 < n and nums[i] > nums[i+1]){
            i++;
        }

        if(i == p) return false;

        int q = i;

        bool checking_last = false;
        while(i+1 < n and nums[i] < nums[i+1]){
            i++;
            checking_last = true;
        }

        return checking_last and i == n-1;
    }
};