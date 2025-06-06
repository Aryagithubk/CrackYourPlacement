class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int close_count = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open_count++;
            }else if(s[i] == ')' and open_count > 0){
                open_count--;
            }else{
                close_count++;
            }
        }

        return open_count+close_count;
    }
};