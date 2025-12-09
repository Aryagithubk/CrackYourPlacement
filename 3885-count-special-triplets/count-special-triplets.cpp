class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> leftCount, rightCount;

        for (int x : nums) rightCount[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            rightCount[mid]--;  

            long long target = mid * 2LL;

            long long leftMatches = leftCount[target];

            long long rightMatches = rightCount[target];

            ans = (ans + (leftMatches * rightMatches) % MOD) % MOD;

            leftCount[mid]++; 
        }

        return ans;
    }

};