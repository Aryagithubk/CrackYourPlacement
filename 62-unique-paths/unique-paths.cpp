class Solution {
public:
    int uniquePaths(int m, int n) {
        //solving by 2d array , t.c - m*n

        vector<vector<int>>dp(m,vector<int>(n,0));

        //base case if 0,0 then only one way to reach
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};