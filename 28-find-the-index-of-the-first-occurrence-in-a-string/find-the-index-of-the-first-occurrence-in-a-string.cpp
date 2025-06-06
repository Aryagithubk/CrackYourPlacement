class Solution {
public:
    int strStr(string h, string nd) {
        int m = h.size(), n = nd.size();
        if(n > m) return -1;
        for(int i = 0;i<=m-n;i++){
            string s = h.substr(i, n);
            if(s == nd) return i;

        }

        return -1;
    }
};