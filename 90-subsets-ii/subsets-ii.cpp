class Solution {
public:
    void helper(int ind,vector<int>&nums,int n,vector<int>&v,vector<vector<int>>&ans){
       ans.push_back(v);

        for(int i=ind; i<n; i++){
            if(i > ind and nums[i] == nums[i-1]){
                continue;
            }
            v.push_back(nums[i]);
            helper(i+1,nums,n,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>ans;

        helper(0,nums,n,v,ans);
        return ans;
    }
};