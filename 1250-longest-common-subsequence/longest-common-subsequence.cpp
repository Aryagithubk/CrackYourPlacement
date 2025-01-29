class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }//hum isiliye one by one dono text se char hta kr dekh re ki maximum lcs kisme aa ra baaki pehle element ka aur hum piche se start kr re match krna.
            }
        }

        return dp[n][m];
    }

    ////dry run
    // text1 = abfc
    // text2= yaf
    // last char is not same i.e c != f so first we delete c from abfc so it will become abf . now lcs of abf and yaf is af i.e 2 and if we remove f from yaf then it becomes ya. so lcs of ya and abfc is 1. so we will take max of 2 and 1 i.e 2.

};