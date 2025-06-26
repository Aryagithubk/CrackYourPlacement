class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;

        for(int i=0; i<n; i++){
                sum += mat[i][i];
                sum += mat[i][n-i-1];
            }
          

    

        if(n%2 != 0){
            // sum = sum - mat[n-2][m-2];//gives runtime error because if n = 1 then index becomes negative so
            sum = sum - mat[n/2][m/2];
        }

        return sum;
    }
};