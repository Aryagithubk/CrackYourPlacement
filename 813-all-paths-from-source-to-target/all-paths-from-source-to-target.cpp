class Solution {
public:
    void helper(int node,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&res){
        path.push_back(node);
        if(node == graph.size()-1){
            res.push_back(path);
        }else{
            for(auto x : graph[node]){
                helper(x,graph,path,res);
            }
        }

        path.pop_back(); // backtracking
       
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>path;
        vector<vector<int>>res;

        helper(0,graph,path,res);
        return res;

        
    }
};