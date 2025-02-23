class Solution {
public:

    void helper(int ind,vector<int>&candidates,int target,int n,vector<int>&v,vector<vector<int>>&ans){
            if(target == 0){
                ans.push_back(v);
                return;
            }

        for(int i=ind; i<n; i++){
            if(i > ind and candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            v.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i],n,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        vector<vector<int>>ans;

        helper(0,candidates,target,n,v,ans);
        return ans;
    }
};