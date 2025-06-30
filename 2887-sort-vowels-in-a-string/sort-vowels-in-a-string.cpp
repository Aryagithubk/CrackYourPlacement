class Solution {
public:
    bool isvowel(char ch){
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        int n = s.length();
        vector<pair<char,int>>vowels;

        for(int i=0; i<n; i++){
            if(isvowel(s[i])){
                vowels.push_back({s[i],i});
            }
        }

        sort(vowels.begin(),vowels.end());

        string ans = "";
        int ind = 0;
        for(int i=0; i<n; i++){
            if(isvowel(s[i])){
                ans += vowels[ind].first;
                ind++;
            }else{
                ans += s[i];
            }
        }

        return ans;
    }
};