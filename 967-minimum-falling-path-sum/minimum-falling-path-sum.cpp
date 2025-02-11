class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp = matrix;

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int top = dp[i-1][j];
                int ldiag = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int rdiag = (j < n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] += min(top,min(ldiag,rdiag));
            }
        }

        int mini = INT_MAX;

        for(int j=0; j<n; j++){
            mini = min(mini,dp[m-1][j]);
        }

        return mini;
    }
};