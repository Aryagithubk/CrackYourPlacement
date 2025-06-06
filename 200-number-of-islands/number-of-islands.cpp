class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col] = 1;
        queue<pair<int,int>>q;

        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        int dx[8] = {0,0,-1,1};
        int dy[8] = {-1,1,0,0};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

                for(int i=0; i<4; i++){
        
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '1'){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};