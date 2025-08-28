class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1){
            return INT_MAX;
        }

        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while(dvd >= dvs){
            long temp = dvs,m=1;
            while(temp<<1 <= dvd){
                temp <<= 1;//multiplying 2^1 to temp means doubling the number
                m <<= 1;//same doubling the count
            }
            dvd -= temp;
            ans += m;
        }

        return sign*ans;
    }
};