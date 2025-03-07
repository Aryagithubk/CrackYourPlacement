class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long long num = x;
        long long rev = 0;

        while(num > 0){
            long long rem = num % 10;
            rev = rev * 10 + rem;

            num = num/10;
        }

        return rev == x;
    }
};