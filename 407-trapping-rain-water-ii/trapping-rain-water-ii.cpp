class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        vector<vector<int>>vis(n,vector<int>(m,false));

        //putting all corner sides wall into priority queue

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heightMap[i][j],i,j});
                    vis[i][j] = true;
                }
            }
        }

        int dirs[] = {-1,0,1,0,-1};//cz k+1 we are using so if k becomes 4 so dx[5] = -1 we can get
        int water = 0;

        while(!pq.empty()){
            auto top = pq.top();
            int curr_height = top[0];
            int row = top[1];
            int col = top[2];
            pq.pop();

            for(int k=0; k<4; k++){
                int dx = row + dirs[k];
                int dy = col + dirs[k+1];

                if(dx >= 0 and dx < n and dy >= 0 and dy < m and vis[dx][dy] != true){
                    water += max(0, curr_height - heightMap[dx][dy]);
                    vis[dx][dy] = true;
                    pq.push({max(curr_height,heightMap[dx][dy]),dx,dy});
                    /*
                    \U0001f4e6 Socho layers mein (like an onion \U0001f9c5):
Let’s take this example:

csharp
Copy
Edit
[5, 5, 5, 5]
[5, 1, 2, 5]
[5, 3, 4, 5]
[5, 5, 5, 5]
Outer boundary = 5 → we start from all 5s

Center cell = 1

Middle cell = 2, 3, 4

\U0001f501 Step by step kya hoga?
Hum sab boundary 5 cells ko min-heap mein daalte hain.

Hum sabse chhoti wall (5) ko nikaalte hain.

Uska neighbor (say 1) ko dekhte hain → 5 - 1 = 4 units paani bharega ✅

Ab woh 1 wala cell abhi bhi ek wall ban gaya (uske aage ke cells ke liye)

Lekin kya woh wall height 1 honi chahiye? ❌ No

Kyunki actual boundary usko protect kar rahi thi → 5

\U0001f9e0 Isliye:
Agar hum 1 height heap mein daal denge,
to agla cell (say 2) soch lega "Oh! Mere paas to 1 height ki wall hai",
aur woh 2 > 1 hone ke kaaran paani nahin bharega — which is wrong. ❌
*/
                }
            }
        }

        return water;




    }
};