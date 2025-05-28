class Solution {
public:
    // Top-down DP to compute length
    int findsubseq(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int nottaken = findsubseq(ind + 1, prev_ind, nums, n, dp);
        int taken = 0;
        if (prev_ind == -1 || nums[ind] % nums[prev_ind] == 0) {
            taken = 1 + findsubseq(ind + 1, ind, nums, n, dp);
        }

        return dp[ind][prev_ind + 1] = max(nottaken, taken);
    }

    // Path reconstruction using dp values
    vector<int> findpath(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        vector<int> ans;
        while (ind < n) {
            int nottaken = findsubseq(ind + 1, prev_ind, nums, n, dp);
            int taken = 0;
            if (prev_ind == -1 || nums[ind] % nums[prev_ind] == 0) {
                taken = 1 + findsubseq(ind + 1, ind, nums, n, dp);
            }

            if (taken > nottaken) { // strict > ensures chain validity
                ans.push_back(nums[ind]);
                prev_ind = ind;
            }
            ind++;
        }
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        sort(nums.begin(), nums.end());

        return findpath(0, -1, nums, n, dp);
    }
};
