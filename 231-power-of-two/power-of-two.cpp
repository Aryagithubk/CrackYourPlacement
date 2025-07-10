class Solution {
public:
    bool isPowerOfTwo(int n) {
    //    if(n <= 0) return false;

    //     while(n%2 == 0){
    //         n = n/2;
    //     }

    //     return n == 1;
    // }

    return n > 0 and (n & (n-1)) == 0;//it will take constant time
    //in case of even number which is power of 2, they and one number decrease like 2 and 1,4 and 3,8 and 7 etc. those even numbers have only one 1 digit and in odd one flipped of zeros i.e 1. eg - 8 has 1000 and 7 has 0111 so and of these two will give 0.
    }
};