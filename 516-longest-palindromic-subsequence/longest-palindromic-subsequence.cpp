class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>>dp(n,vector<int>(n,0));

        //for single character
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }

        //for 2 or more than

        for(int i=2; i<=n; i++){
            for(int j=0; j<=n-i; j++){
                int k = j + i - 1;

                if(s[j] == s[k]){
                    dp[j][k] = 2 + dp[j+1][k-1];
                }else{
                    dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};