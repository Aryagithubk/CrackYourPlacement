class Solution {
public:
    int countHousePlacements(int n) {
        const long long mod = 1000000007;  // Define mod as a constant
        vector<long long> dp(n + 1, 0);

        if (n == 1) {
            return 4;
        }

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return (dp[n] * dp[n]) % mod;
    }
};
