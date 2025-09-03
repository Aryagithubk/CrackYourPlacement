class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        string str1 = s+s;
        if(str1.find(goal) != string::npos){
            return true;
        }else{
            return false;
        }
    }
};