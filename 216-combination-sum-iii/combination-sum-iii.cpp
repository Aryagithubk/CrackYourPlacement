class Solution {
public:
    void helper(int start,int k,int n,vector<int>&v,vector<vector<int>>&ans){
        if(k == 0 and n == 0){
            ans.push_back(v);
        }
        if(k == 0 || n < 0){
            return;
        }

        for(int i=start; i<=9; i++){
            v.push_back(i);
            helper(i+1,k-1,n-i,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>>ans;

        helper(1,k,n,v,ans);
        return ans;
    }
};