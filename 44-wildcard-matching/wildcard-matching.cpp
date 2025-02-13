class Solution {
public:
    bool isOnlyStar(string &p,int j){
        for(int i=0; i<=j; i++){
            if(p[i] != '*'){
                return false;
            }
        }
        return true;
    }
    bool helper(string &s,string &p, int i,int j,vector<vector<int>>&dp){
        if(i < 0 and j < 0){
            return true;
        }
        if(i < 0 and j>=0){
            return isOnlyStar(p,j);
        }
        if(i >= 0 and j < 0){
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = helper(s,p,i-1,j-1,dp);
        }else{
            if(p[j] == '*'){
                return dp[i][j] = helper(s,p,i-1,j,dp) || helper(s,p,i,j-1,dp);
            }else{
                return false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,p,n-1,m-1,dp);
    }
};