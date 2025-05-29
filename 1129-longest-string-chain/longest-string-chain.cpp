class Solution {
public:
    bool compare(string &s1,string &s2){
        if(s1.size() != 1 + s2.size()) return false;

        int first = 0; 
        int second = 0;

        while(first < s1.size()){
            if(second < s2.size() and s1[first] == s2[second]){
                first++;
                second++;
            }else{
                first++;
            }        
        }

        if(first == s1.size() and second == s2.size()) return true;

        return false;

    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n  =words.size();

        // sort(words.begin(),words.end());//as it will not in lexicographical order which we dont need . as we need sorting based on length of word.
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=0; j<=i-1; j++){
                if(compare(words[i],words[j]) and 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
};