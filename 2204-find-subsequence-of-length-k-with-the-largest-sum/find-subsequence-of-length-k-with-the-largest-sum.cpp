class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>arr;

        for(int i=0; i<n; i++){
            arr.push_back({nums[i],i});
        }//storing with original indexes

        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });//sorting in descending order

        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(arr[i].second);//storing top k elements index bcz these are highest element which will give highest sum
        }

        sort(ans.begin(),ans.end());

        vector<int>res;
        for(auto it : ans){
            res.push_back(nums[it]);
        }//now storing those elements in resultant array

        return res;
    }
};