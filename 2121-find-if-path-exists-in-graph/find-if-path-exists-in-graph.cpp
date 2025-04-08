class Solution {
public:
    bool helper(int source, int dest, vector<vector<int>>&adj,vector<bool>&vis){
        if(source == dest) return true;
        vis[source] = true;

        for(int x : adj[source]){
            if(!vis[x]){
                if(helper(x,dest,adj,vis)) return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        return helper(source,destination,adj,vis);
    }
};