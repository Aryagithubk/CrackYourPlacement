class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        map<char,int>mp;
        int depth = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                depth++;
            }else if(s[i] == ')'){
                depth--;
            }
           
            mp[s[i]] = max(mp[s[i]],depth);//hum ye isiliye likhe taki agar koi digit char repeat ho ra ho toh hum wo digit le jiska depth jyada h . wrna agar saare unique digit rhte toh hum simple mp[s[i]] = depth likh skte the.
            }
        

        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi,it.second);
        }

        return maxi;
    }
};