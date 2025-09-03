class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //agar hum sort krdenge toh suru ka agar last wale se match kra mtlb sb match kr jaayega bich wale v otherwise break , no common
        sort(strs.begin(),strs.end());

        int i=0,j=0;
        int n = strs.size();
        string ans = "";
        while(i < strs[0].size() and j < strs[n-1].size()){
            if(strs[0][i] != strs[n-1][j]){
                break;
            }else{
                ans += strs[0][i];
                i++,j++;
            }
        }

        return ans;
    }
};