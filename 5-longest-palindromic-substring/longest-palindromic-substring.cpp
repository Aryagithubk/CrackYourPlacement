class Solution {
public:
    bool ispalin(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2){
            return s;
        }

        string maxi = "";

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i] == s[j] and ispalin(s,i,j)){
                    int len = j-i+1;
                    if(len > maxi.size()){
                        maxi = s.substr(i,len);
                    }

                }
            }
        }

        return maxi;

    }
};