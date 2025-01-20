class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i] += dp[j-1] * dp[i-j];//for each sub problem we r tsking i as j and n as i
            }
        }

        return dp[n];
    }
};