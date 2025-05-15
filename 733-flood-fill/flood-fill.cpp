class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,vector<vector<int>>&ans,int inicolor,int delrow[], int delcol[]){
    ans[sr][sc] = color;
    int n = image.size();
    int m = image[0].size();

    for(int i=0; i<4; i++){
    int nrow = sr + delrow[i];
    int ncol = sc + delcol[i];

    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == inicolor and ans[nrow][ncol] != color){
    dfs(image,nrow,ncol,color,ans,inicolor,delrow,delcol);
    }
    }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>>ans = image;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        dfs(image,sr,sc,color,ans,inicolor,delrow,delcol);
        return ans;



    }
};