class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;

        int n = arr.size();
        for(auto it : arr){
            mp[it]++;
        }

        int ans = -1;

        for(auto it : mp){
            if(it.first == it.second){
                ans = max(ans,it.first);
            }
        }

        return ans;
    }
};