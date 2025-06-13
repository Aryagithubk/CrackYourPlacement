class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<vector<int>>ans = image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;

        q.push({sr,sc});
        ans[sr][sc] = color;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()){
            int sz = q.size();
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int inicolor = image[x][y];

                for(int i=0; i<4; i++){
                    int nrow = x + dx[i];
                    int ncol = y + dy[i];

                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == inicolor and ans[nrow][ncol] != color ){
                        ans[nrow][ncol] = color;
                        q.push({nrow,ncol});
                    }
                }
        }

        return ans;
    }
};