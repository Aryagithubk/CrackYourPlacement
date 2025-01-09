class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int l = pref.length();
        int count = 0;
        for(int i=0; i<words.size(); i++){
            string s1 = words[i];

            string str = s1.substr(0,l);
            if(str == pref){
                count++;
            }
        }

        return count;
    }
};