class disjointSet {
    public:
    vector<int> rank, parent, size;
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<n; i++){
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
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

    void unionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
private:
    bool isValid(int newr,int newc, int n){
        return newr >= 0 and newr < n and newc >= 0 and newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n*n);

        //we will connect each cell into components
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int ind=0; ind < 4; ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];

                    if(isValid(newr,newc,n) and grid[newr][newc] == 1){
                        int node = i * n + j;
                        int adjnode = newr * n + newc;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }

        //now we put 1 and try to find possible big component 
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                set<int>comp;
                for(int ind=0; ind<4; ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc] == 1){
                            comp.insert(ds.findParent(newr * n + newc));
                        }
                    }
                }
                int sz = 0;
                for(auto it : comp){
                    sz += ds.size[it];
                }

                mx = max(mx,sz + 1);
            }
        }

        //agar saaare cell 1 ho

        for(int i=0; i<n*n; i++ ){
            mx = max(mx,ds.size[ds.findParent(i)]);
        }

        return mx;
    }
};