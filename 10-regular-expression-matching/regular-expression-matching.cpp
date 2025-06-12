class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    // Function to check if s[i...] matches p[j...]
    bool solve(int i, int j, string& s, string& p) {
        // Base case: if pattern is finished
        if (j == m) {
            return i == n;  // return true only if string is also finished
        }

        // If already calculated, return stored result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Check if characters match at i and j (also handle '.')
        bool match = false;
        if (i < s.length()) {
            if (s[i] == p[j] || p[j] == '.') {
                match = true;
            }
        }

        // Handle '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Two cases:
            // 1. Skip the 'x*' part → solve(i, j + 2)
            // 2. If match, try to use current character → solve(i + 1, j)
            bool result = solve(i, j + 2, s, p);  // skip
            if (match) {
                result = result || solve(i + 1, j, s, p);  // consume
            }
            dp[i][j] = result;
            return result;
        }

        // No '*', just move to next characters if current matches
        if (match) {
            dp[i][j] = solve(i + 1, j + 1, s, p);
            return dp[i][j];
        }

        // No match
        dp[i][j] = false;
        return false;
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();

        // Initialize dp table with -1 (uncomputed)
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, s, p);
    }
};
