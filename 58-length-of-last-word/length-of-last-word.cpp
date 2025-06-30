class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        int j = 0;
        for(j=n-1; j>=0; j--){
            if(s[j] != ' '){
                break;
            }
        }
        int i = 0;
        for(i=j; i>=0; i--){
            if(s[i] == ' '){
                break;
            }
        }

        return j-i;
    }
};