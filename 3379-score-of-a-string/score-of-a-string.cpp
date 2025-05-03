class Solution {
public:
    int scoreOfString(string s) {
        // char x = 'a';
        // int  val = x;
        // cout<<val<<endl;
        int sum = 0;
        for(int i=0; i<s.length()-1; i++){
            char str1 = s[i];
            char str2 = s[i+1];
            int x = str1, y = str2;
            int diff = abs(x-y);
            sum += diff;
        }

        return sum;
    }
};