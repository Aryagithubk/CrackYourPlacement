class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //ab hum ek map bnayenge jisme wo index diff honge jisko ascending order me krna h same ek aur map for descending order.
        //agar diff positive h mtlb niche ka section mtlb descending order
        //agar diff neg h mtlb uper ka section mtlb ascending order
        unordered_map<int,priority_queue<int>>maxheaps;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>minheaps;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int diff = i-j;
                if(diff < 0){
                    minheaps[diff].push(grid[i][j]);
                }else{
                    maxheaps[diff].push(grid[i][j]);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int diff = i-j;
                if(diff < 0){
                    grid[i][j] = minheaps[diff].top();
                    minheaps[diff].pop();
                }else{
                    grid[i][j] = maxheaps[diff].top();
                    maxheaps[diff].pop();
                }
            }
        }

        return grid;
    }

    /*
    maxHeaps[0] = {3,2,1}   (max-heap → 3 on top)
    maxHeaps[1] = {2,1}     (2 on top)
    maxHeaps[2] = {1}       (1 on top)
    minHeaps[-1] = {3,1}    (min-heap → 1 on top)
    minHeaps[-2] = {1}      (1 on top)

    Reconstruct grid

Now we traverse matrix again and replace with sorted values:

At (0,0) key=0 → take from maxHeaps[0]: top=3 → grid[0][0]=3 → pop → heap {2,1}

At (0,1) key=-1 → take from minHeaps[-1]: top=1 → grid[0][1]=1 → pop → heap {3}

At (0,2) key=-2 → take from minHeaps[-2]: top=1 → grid[0][2]=1 → heap empty

At (1,0) key=1 → from maxHeaps[1]: top=2 → grid[1][0]=2 → heap {1}

At (1,1) key=0 → from maxHeaps[0]: top=2 → grid[1][1]=2 → heap {1}

At (1,2) key=-1 → from minHeaps[-1]: top=3 → grid[1][2]=3 → heap empty

At (2,0) key=2 → maxHeaps[2]: top=1 → grid[2][0]=1

At (2,1) key=1 → maxHeaps[1]: top=1 → grid[2][1]=1

At (2,2) key=0 → maxHeaps[0]: top=1 → grid[2][2]=1
*/


};