class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = "";
        int count = 0;

        while(str.length() < b.length()){
            str += a;
            count++;
        }
        if(str.find(b) != -1){
            return count;
        }
        str += a;
        count++;

        if(str.find(b) != -1){
            return count;
        }

        return -1;
    }
};