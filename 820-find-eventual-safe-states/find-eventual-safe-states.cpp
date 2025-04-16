class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();

       vector<vector<int>>revadj(n);
       vector<int>indegree(n,0); 

       //reverse graph bnayenge
       for(int i=0; i<n; i++){
        // int u = graph[i][0], v = graph[i][1];
        // revadj[v].push_back(u);
        //hum ye nhi krenge kyuki ye tb hota h jb incoming outgoing edge fix ho but isme kitne v ho skte hai isiliye
        for(int x : graph[i]){
            revadj[x].push_back(i);
        indegree[i]++;
        }
       }

       //indegree count
       queue<int>q;

       for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
       }

       vector<int>ans;
       vector<bool>safe(n,false);

       while(!q.empty()){
        int top = q.front();
        q.pop();
        safe[top] = true;

        for(int x : revadj[top]){
            indegree[x]--;

            if(indegree[x] == 0){
                q.push(x);
            }
        }
       }

       for(int i=0; i<n; i++){
        if(safe[i]){
            ans.push_back(i);
        }
       }

       return ans;
    }
};