class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string res = "";
        int sum = 0;
        int carry = 0;

        while(i >=0 || j>=0 || carry){
            sum = carry;
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }

            res += (sum % 2) + '0';

            carry = sum/2;


        }

        reverse(res.begin(),res.end());
        return res;
    }
};