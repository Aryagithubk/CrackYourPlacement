class Solution {
public:
    char helper(int shift, int k){
        if(k == 1) return ('a' + shift%26);

        int len = 1;
        while(len * 2 < k){
            len = len*2;
        }

        if(k <= len){
            return helper(shift,k);
        }else{
            return helper(shift+1,k-len);
        }
    }
    char kthCharacter(int k) {
        return helper(0,k);
    }
    
};