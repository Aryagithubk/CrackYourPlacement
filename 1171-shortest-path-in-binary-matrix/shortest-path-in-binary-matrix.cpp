class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int source[] = {0,0};
        int dest[] = {n-1,n-1};
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        
        if(source[0] == dest[0] and source[1] == dest[1]){
            return 1;
        } 

        queue<pair<int,pair<int,int>>>q;

        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[source[0]][source[1]] = 1;
        q.push({1,{source[0],source[1]}});

        int dr[] = {-1,-1,0,1,1,1,0,-1};
        int dc[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int nrow = it.second.first;
            int ncol = it.second.second;

            for(int i=0; i<8; i++){
                int r = nrow + dr[i];
                int c = ncol + dc[i];

                if(r >= 0 and r < n and c >= 0 and c < n and grid[r][c] == 0 and dis + 1 < dist[r][c]){
                    dist[r][c] = dis+1;

                    if(r == dest[0] and c == dest[1]){
                        return dis+1;
                    }
                    q.push({dis+1,{r,c}});
                }
            }
        }

        return -1;
    }
};