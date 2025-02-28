#include <regex>
class Solution {
public:
    vector<string>split(string parts,char dots){
        vector<string>res;
        string temp = "";

        for(char c : parts){
            if(c == dots){
                res.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }

        res.push_back(temp);

        return res;

    }
    bool isIPV4(string queryIP){
        vector<string>v = split(queryIP,'.');

        if(v.size() != 4){
            return false;
        }

        for(string parts : v){
            if(parts.size() > 3 || parts.empty())return false;

            for(char c : parts){
            if(!isdigit(c)) return false;
            }
            int num = stoi(parts);

            if(num > 255 || num < 0) return false;

            if(parts[0] == '0' and parts.length() > 1){
                return false;
            }

        }

        return true;
    }

    bool isIPV6(string queryIP){
        vector<string>v = split(queryIP,':');

        if(v.size() != 8){
            return false;
        }

        for(string parts : v){
            if(parts.empty() || parts.size() > 4){
                return false;
            }

            for(char c : parts){
                if(!isxdigit(c)) return false;
            }
        }

        return true;
    }

    string validIPAddress(string queryIP) {
        if(isIPV4(queryIP)){
            return "IPv4";
        }else if(isIPV6(queryIP)){
            return "IPv6";
        }else{
            return "Neither";
        }
    }
};