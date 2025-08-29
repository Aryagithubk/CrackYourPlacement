class Solution {
public:
    long long flowerGame(int n, int m) {
        // long long count = 0;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if((i+j)%2 != 0){
        //             count++;
        //         }
        //     }
        // }

        // return count;

        long long evenx = n/2;
        long long oddx = (n+1)/2;
        long long eveny = m/2;
        long long oddy = (m+1)/2;

        return (evenx*oddy) + (oddx*eveny);
        /*as we know that to make pair whose sum is odd. it means one number should be odd and other even. so this is a way of finding total such pairs.
        
        e.g. Example check: n=3, m=2

            oddX = (3+1)/2 = 2 → {1,3}
            evenX = 3/2 = 1 → {2}
            oddY = (2+1)/2 = 1 → {1}
            evenY = 2/2 = 1 → {2}
            count = (21) + (11) = 3
            */
    }
};