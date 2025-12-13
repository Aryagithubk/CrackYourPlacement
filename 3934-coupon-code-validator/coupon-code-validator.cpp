class Solution {
public:
    bool isLine(string &s){
        string str[] = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(const string &i : str){
            if(i == s){
                return true;
            }
        }

        return true;
    }

    bool isValid(const string& code){
        if(code.empty()) return false;
        for(char c: code){
            if(!(isalnum(c) || c == '_')) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, vector<string>>mp;
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        int n = code.size();
        for(int i=0; i<n; i++){
            if(isActive[i] and isValid(code[i]) and isLine(code[i])){
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string>res;

        for(string &line: order){
            sort(mp[line].begin(),mp[line].end());
            for(string &c: mp[line]){
                res.push_back(c);
            }
        }

        return res;
    }

};