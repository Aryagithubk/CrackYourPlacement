class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 and col == m-1){
                return diff;
            }

            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m){

                int maxieffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);

                if(maxieffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = maxieffort;
                    pq.push({maxieffort,{nrow,ncol}});
                }
            }
        }
     }

        return 0;
    }
};