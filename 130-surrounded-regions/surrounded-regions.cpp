class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&board,int delrow[4],int delcol[4]){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<4; i++){
            int nx = row + delrow[i];
            int ny = col + delcol[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'O'){
                dfs(nx,ny,vis,board,delrow,delcol);
            } 
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(),m = board[0].size();
        //direction
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traversing first and last row
        
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0,j,vis,board,dx,dy);
            }

            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board,dx,dy);
            }
        }
        //traversing first and last column
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,vis,board,dx,dy);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board,dx,dy);
            }
        }

        //traversing each row and column to make unvisited 0 as X

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }




    }
};