class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count = 0;

        //if we have string of 1 size
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            count++;
        }

        //if string of 2 length
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                count++;
            }
        }

        //greater than 3 or equal size

        for(int len=3; len<=n; len++){
            for(int j = 0; j<= n-len; j++){
                int k = j + len - 1;

                if(s[j] == s[k] && dp[j+1][k-1]){
                    dp[j][k] = true;
                    count++;
                }
            }
        }

        return count;
    }
};