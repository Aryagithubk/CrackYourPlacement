class Solution {
public:

    void f(int i,int n,vector<int>ds,vector<int>&nums,vector<vector<int>>&ans){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        //not pick 
        f(i+1,n,ds,nums,ans);

        //pick
        ds.push_back(nums[i]);
        f(i+1,n,ds,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int>ds;
        vector<vector<int>>ans;

        f(i,n,ds,nums,ans);

        return ans;
    }
};