class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n == 0){
            return "";
        }
        int maxi = 1,start = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        //for 1 length
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }

        //for 2 length
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxi = 2;
            }
        }

        //for 3 or more than

        for(int len=3; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j = i + len -1;

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;

                    if(len > maxi){
                        start = i;
                        maxi = len;
                    }
                }
            }
        }

        return s.substr(start,maxi);
    }
};