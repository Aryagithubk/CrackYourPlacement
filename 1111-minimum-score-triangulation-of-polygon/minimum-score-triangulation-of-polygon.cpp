class Solution {
public:
    int fxn(int i,int j,vector<int>&values,vector<vector<int>>&dp){
        if((j-i) < 2){
            return 0;
        }

        int mini = INT_MAX;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        for(int k = i+1; k<j; k++){
            int score = values[i]*values[k]*values[j] 
            + fxn(i,k,values,dp) 
            + fxn(k,j,values,dp);

            mini = min(mini,score);

        }

        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return fxn(0,n-1,values,dp);
    }
};