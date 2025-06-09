class Solution {
public:
    void helper(string &digits,int ind,string str,vector<string>&res,unordered_map<char,string>&mp){
        if(ind == digits.size()){
            res.push_back(str);
            return;
        }

        string letters = mp.at(digits[ind]);
        for(char ch : letters){
            helper(digits,ind+1,str+ch,res,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;

        if(digits.empty()){
            return {};
        }
        unordered_map<char,string>mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        helper(digits,0,"",res,mp);
        return res;
    }
};