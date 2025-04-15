class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        //graph bnayenge because edges given h

        for(int i=0; i<prerequisites.size(); i++){
            int x = prerequisites[i][0], y = prerequisites[i][1];
            adj[y].push_back(x);
            indegree[x]++;
        }

        queue<int>q;

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;

            for(int node : adj[top]){
                indegree[node]--;

                if(indegree[node] == 0){
                    q.push(node);
                }
            }
        }

        if(count == numCourses){
            return true;
        }

        return false;
    }
};