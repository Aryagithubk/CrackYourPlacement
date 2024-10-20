class Solution {
public:

    void f(int i,int j,int n,vector<string>&ans,string s){
        if(i == n and j == n){
            ans.push_back(s);
            return;
        }

        if(i < n){
            f(i+1,j,n,ans,s + "(");
        }
        if(j < i){
            f(i,j+1,n,ans,s + ")");
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int i = 0;
        int j = 0;
        string s = "";

        f(i,j,n,ans,s);

        return ans;
    }
};