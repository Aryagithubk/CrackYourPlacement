class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

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

        vector<int>ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(int x : adj[top]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }

        if(ans.size() == numCourses){
            return ans;
        }

        return {};  
    }
};