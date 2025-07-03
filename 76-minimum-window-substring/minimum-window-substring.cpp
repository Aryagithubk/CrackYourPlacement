class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n < m){
            return "";
        }

        unordered_map<char,int>need,window;
        for(int ch : t){
            need[ch]++;
        }
        int left = 0,right = 0;
        int minilen = INT_MAX;
        int start = 0;
        int have = 0;

        while(right < n){
            char ch = s[right];
            window[ch]++;
            if(need.find(ch) != need.end() and window[ch] == need[ch]){
                have++;
            }
            //otherwise hum shrink krenge usme v shyd ho skta h wo character shrink ho jaye jo jruri tha but hum shrink me unwanted ke sath sath length minimise krne pe v dhyan de re
            while(have == need.size()){
                if((right - left + 1) < minilen){
                    minilen = right - left + 1;
                    start = left;
                }
                char leftchar = s[left];
                window[leftchar]--;

                if(need.find(leftchar) != need.end() and window[leftchar] < need[leftchar]){
                    have--;
                }

                left++;
            }

            right++;
        }

        if(minilen == INT_MAX){
            return "";
        }

        return s.substr(start,minilen);
    }
};