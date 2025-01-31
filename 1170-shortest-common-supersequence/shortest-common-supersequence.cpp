class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        //make dp table 
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);//as we want to keep maximum subsequnces for better computation in later
                }
            }
        }

        //making scs
        string res = "";
        int i = m,j = n;

        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                res += str1[i-1];
                i--;
                j--; 
            }else if(dp[i-1][j] > dp[i][j-1]){
                res += str1[i-1];
                i--;
            }else{
                res += str2[j-1];
                j--;
            }
        }
        //if chars of str1 only left str2 ended
        while(i > 0){
            res += str1[i-1];
            i--;
        }
        // if chars of str2 only left str1 ended
        while(j > 0){
            res += str2[j-1];
            j--;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};