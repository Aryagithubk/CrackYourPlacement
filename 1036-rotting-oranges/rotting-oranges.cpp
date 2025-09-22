class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));//cz we are traversing matrix

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }

        int maxi_time = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int c = q.front().second;

            maxi_time = max(maxi_time,c);
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = a + dx[i];
                int ncol = b + dy[i];

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},c+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 and grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return maxi_time;

    }
};