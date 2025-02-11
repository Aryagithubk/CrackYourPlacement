class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&grid,int m,vector<vector<int>>&dp){
        if(i == m-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int below = grid[i][j] + helper(i+1,j,grid,m,dp);
        int diag = grid[i][j] + helper(i+1,j+1,grid,m,dp);

        return dp[i][j] = min(below,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return helper(0,0,triangle,m,dp);
    }
};