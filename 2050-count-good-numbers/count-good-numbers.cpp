class Solution {
public:
    const int mod = 1e9 + 7;

    long long helper(long long base, long long exp, int mod){
        long long res = 1;
        base = base % mod;

        while(exp > 0){
            if(exp % 2 == 1){
                res = (res * base) % mod;
            }

            base = (base * base) % mod;
            exp = exp/2;
        }

        return res;

    }
    int countGoodNumbers(long long n) {
        long long even_pos = (n+1)/2;
        long long odd_pos = n/2;

        long long evenpos_val = helper(5,even_pos,mod);
        long long oddpos_val = helper(4,odd_pos,mod);

        return (evenpos_val * oddpos_val) % mod;


    }
};