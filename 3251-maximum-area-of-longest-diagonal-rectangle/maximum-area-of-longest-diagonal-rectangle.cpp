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

       // Sort by diagonal first, then by area
        sort(v.begin(), v.end(), [](const pair<double,int>& a, const pair<double,int>& b){
            if (a.first == b.first) 
                return a.second < b.second;  // for equal diagonals, sort by area
            return a.first < b.first;        // otherwise, sort by diagonal
        });
        cout<<v[n-1].first<<" "<<v[n-1].second<<endl;
        if(n >=2)cout<<v[n-2].first<<" "<<v[n-2].second<<endl;
       return v[n-1].second;
        
    }
};