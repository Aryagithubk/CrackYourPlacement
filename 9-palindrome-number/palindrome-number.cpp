class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        stack<int>st;
        int num = x;

        while(num > 0){
            st.push(num%10);
            num = num/10;
        }

        num = x;

        while(!st.empty()){
            int digit = st.top();
            st.pop();

            if(digit != num%10){
                return false;
            }

            num = num/10;
        }

        return true;
    }
};