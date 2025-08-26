class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       vector<pair<double, int>>v;
       int n = dimensions.size();
       for(int i = 0 ; i<n; i++){
        int l = dimensions[i][0];
        int w = dimensions[i][1];
        double diag = sqrt(l*l + w*w);
        int area = l*w;
        v.push_back({diag, area});
       }

       sort(v.begin(), v.end());
       return v[n-1].second;
        
    }
};