class Solution {
public:
    bool palindrome(int i,int j,string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int partitioning(int i,int n,string &s, vector<int>&dp){
        if(i == n) return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int mini = INT_MAX;

        for(int j=i; j<n; j++){
            if(palindrome(i,j,s)){
                int cost = 1 + partitioning(j+1,n,s,dp);
                mini = min(mini,cost);
            }
        }

        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n,-1);

        return partitioning(0,n,s,dp) - 1;
    }
};