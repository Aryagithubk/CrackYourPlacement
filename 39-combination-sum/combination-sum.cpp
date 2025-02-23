class Solution {
public:
    void helper(int ind,vector<int>&candidates,int target,vector<int>&v,int n,vector<vector<int>>&ans){
        if(ind == n){
            if(target == 0){
                ans.push_back(v);
            }

            return;
        }

        //pick
        if(candidates[ind] <= target){
            v.push_back(candidates[ind]);
            helper(ind,candidates,target-candidates[ind],v,n,ans);
            v.pop_back();//backtracking
        }

        //not pick
        helper(ind+1,candidates,target,v,n,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>v;
        vector<vector<int>>ans;

        helper(0,candidates,target,v,n,ans);
        return ans;

    }
};