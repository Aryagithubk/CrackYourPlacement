class Solution {
public:
    int minimumDeletions(string s) {
        int bcount = 0;
        int del = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == 'b'){
                bcount++;
            }else{
                del = min(del+1,bcount);
            }
        }

        return del;
    }
};