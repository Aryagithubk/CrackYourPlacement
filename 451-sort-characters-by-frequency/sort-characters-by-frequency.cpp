class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        map<char,int>mp;

        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second > b.second;
        });

        string s2 = "";
        for(auto &it : v){
            for(int i=0; i<it.second; i++){
              s2 += it.first;

            }
        }

        return s2;
    }
};