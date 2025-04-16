class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;


            int maxirow = 0;
        while(low <= high){
            int mid = low + (high - low)/2;

            for(int i=0; i<n; i++){
                if(mat[i][mid] > mat[maxirow][mid]){
                    maxirow = i;
                }
            }

            int left = (mid - 1 >= 0) ? mat[maxirow][mid-1] : -1;
            int right = (mid + 1 < m) ? mat[maxirow][mid + 1] : -1;

            if(mat[maxirow][mid] > left and mat[maxirow][mid] > right){
                return {maxirow,mid};
            }else if(left > mat[maxirow][mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
                }
            }

            return {-1,-1};

        }
};