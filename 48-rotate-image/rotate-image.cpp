class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i < j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        for(int i=0; i<n; i++){
                // matrix[i][j] = matrix[i][n-j-1];//overwriting ho jayega jo galat h
                reverse(matrix[i].begin(),matrix[i].end());
            }
    }
};