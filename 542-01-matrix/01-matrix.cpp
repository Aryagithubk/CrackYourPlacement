class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>v;

        //hum 0 ko queue me daal re usko 0 hi rhne de re

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        //ab hum direction define krenge
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        //bfs traversing krenge

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                //neighbours me ja re
                int nx = x + dx[i];
                int ny = y + dy[i];
                //kuch boundaries check kr re

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = d + 1;
                    q.push({{nx,ny},d+1});
                }
            }
        }

        return dist;
    }
};