class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int n1 = num1.length();
        int n2 = num2.length();
        vector<int>ans(n1+n2,0);

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
               int mul = (num1[i] - '0') * (num2[j] - '0');
               int sum = ans[i+j+1] + mul;

                ans[i+j+1] = sum%10;
                ans[i+j] += sum/10;
            }
        }

        string str = "";
        bool res = false;

        for(int i=0; i<ans.size(); i++){
            if(ans[i] != 0){
                res = true;
            }
            if(ans[i] == 0 and res != true) continue;
            res = true;
            char ch = ans[i] + '0';
            str += ch;

        }

        return str;
    }
};