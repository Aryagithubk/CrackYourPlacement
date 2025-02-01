class Solution {
public:
    pair<int,int> countzeros(const string &s){
        int zero = 0, ones = 0;
        for(char c : s){
            if(c == '0'){
                zero++;
            }else{
                ones++;
            }
        }

        return {zero,ones};
    }

    int fxn(vector<string>&strs, int m, int n, int index,vector<vector<vector<int>>>&dp){
        if(index == strs.size()){
            return 0;
        }
        if(dp[index][m][n] != -1){
            return dp[index][m][n];
        }

        auto [zeros,ones] = countzeros(strs[index]);

        int res1 = fxn(strs,m,n,index+1,dp);//not considering current string
        int res2 = 0;
        if(zeros <= m && ones <= n){
        res2 = 1 + fxn(strs,m-zeros,n-ones,index+1,dp);

        }//considering the string

        return dp[index][m][n] = max(res1,res2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return fxn(strs,m,n,0,dp);
    }
};