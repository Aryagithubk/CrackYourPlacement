class Solution {
public:
    int fxn(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        //base case
        //if j went to negative 
        //means once each char has been traversed
        if(j < 0){
            return 1;
        }
        //if i went to negative and j still pointing some char 
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return dp[i][j] = fxn(i-1,j-1,s,t,dp) + fxn(i-1,j,s,t,dp);//adding cond of matching chr then consider it or matching but dont want to consider it ..adding both cond;
        }
        return dp[i][j] = fxn(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return fxn(n-1,m-1,s,t,dp);
    }
};