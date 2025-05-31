class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi_profit = 0;
        int mini_ele = prices[0];

        for(int i=1; i<n; i++){
            int cost = prices[i] - mini_ele;
            maxi_profit = max(maxi_profit,cost);
            mini_ele = min(mini_ele,prices[i]);
        }

        return maxi_profit;
    }
};