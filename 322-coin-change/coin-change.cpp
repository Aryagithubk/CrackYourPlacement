class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int>prev(amount + 1,0);
        vector<int>curr(amount + 1,0);

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }else{
                prev[i] = 1e9;
            }
        }

        for(int ind = 1; ind < n; ind++){
            for(int tar = 0; tar <= amount; tar++){
                int nottaken = prev[tar];

                int taken = 1e9;
                if(coins[ind] <= tar){
                    taken = 1 + curr[tar - coins[ind]];
                }

                curr[tar] = min(nottaken,taken);
            }

            prev = curr;
        }

        int ans = prev[amount];

        if(ans >= 1e9){
            return -1;
        }

        return ans;
    }
};