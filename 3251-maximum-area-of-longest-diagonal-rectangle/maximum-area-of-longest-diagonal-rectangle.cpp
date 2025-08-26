class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxarea = 0;
        int len =0,wid=0;
        double maxdiag = 0;
        
        for(int i=0; i<n; i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int val = l*l + w*w;
            double curdiag = sqrt(val);
            int curarea = l*w;
            if(curdiag > maxdiag){
                maxarea = curarea;
                maxdiag = curdiag;
            }else if(curdiag == maxdiag){
                maxarea = max(maxarea, curarea);
            }
        }
            return maxarea;
        
    }
};