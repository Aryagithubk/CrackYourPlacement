class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int maxi_row = 0;//bydefault we are taking row value index 0

            for(int i=0; i<n; i++){
                if(mat[i][mid] > mat[maxi_row][mid]){
                    maxi_row = i;
                }
            }
            int case1 = (mid-1 >= 0)? mat[maxi_row][mid-1] : -1;//getting left value 
            int case2 = (mid+1 <= m-1) ? mat[maxi_row][mid+1] : -1; //getting last value

            if(mat[maxi_row][mid] > case1 and mat[maxi_row][mid] > case2){
                return {maxi_row,mid};
            }else if(mat[maxi_row][mid] < case2){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return {-1,-1};
    }
};