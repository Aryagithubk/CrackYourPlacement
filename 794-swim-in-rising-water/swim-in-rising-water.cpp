class disjointset {
    public:
    vector<int> rank, parent, size;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        vector<pair<int,pair<int,int>>>cells;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cells.push_back({grid[i][j],{i,j}});
            }
        }

        sort(cells.begin(),cells.end());
        vector<vector<bool>>vis(n,vector<bool>(n,false));

        disjointset ds(n*n);

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        for(auto &it : cells){
            int t = it.first;
            int row = it.second.first;
            int col = it.second.second;
            int node = row * n + col;
            vis[row][col] = true;

            for(int i=0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 and newr < n and newc >= 0 and newc < n and vis[newr][newc]){
                    int adjnode = newr * n + newc;
                    ds.unionBySize(node,adjnode);
                }
            }

            if(ds.findParent(0) == ds.findParent(n*n - 1)){
                return t;
            }
        }

        return -1;
    }
};