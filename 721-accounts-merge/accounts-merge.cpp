class DisjointSet {
    vector<int>rank, parent, size;
    public:
    DisjointSet(int n){
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

    void unionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        //hum union krenge pehle unn nodes ko jisme same emails mile
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
    //ab hum merge krenge ultimate parent dekh kr
        vector<string>mergemail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergemail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0; i<n; i++){
            if(mergemail[i].size() == 0)continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);//hum name push kr re usko v include krna hai
            for(auto it :mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
    
};