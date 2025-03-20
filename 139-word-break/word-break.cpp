class Solution {
public:
    bool helper(string s, unordered_set<string>&st,unordered_map<string,bool>&memo){
        if(s.empty()){
            return true;
        }

        if(memo.find(s) != memo.end()){
            return memo[s];
        }
        for(int i=1; i<= s.length(); i++){
            string part1 = s.substr(0,i);

            if(st.find(part1) != st.end()){
                string part2 = s.substr(i);

                if(helper(part2,st,memo)){
                    return memo[s] = true;
                }
            }
        }

        return memo[s] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        unordered_map<string,bool>memo;
        return helper(s,st,memo);
    }
};