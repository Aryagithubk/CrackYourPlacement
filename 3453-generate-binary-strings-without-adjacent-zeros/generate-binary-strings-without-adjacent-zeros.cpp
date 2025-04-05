class Solution {
public:
    void helper2(int n, string s, int start,vector<string>&ans){
    
        if(start == n){
            ans.push_back(s);
            return;
        }

        if(s[start-1] == '0'){
            s[start] = '1';
            helper2(n,s,start+1,ans);
        }

        if(s[start-1] == '1'){
            s[start] = '1';
            helper2(n,s,start+1,ans);

            s[start] = '0';
            helper2(n,s,start+1,ans);
        }
    }
    void helper1(int n,vector<string>&ans){
        if(n < 0){
            return;
        }

        string str(n,'0');
        str[0] = '0';
        helper2(n,str,1,ans);

        str[0] = '1';
        helper2(n,str,1,ans);

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        helper1(n,ans);
        return ans;

    }
};