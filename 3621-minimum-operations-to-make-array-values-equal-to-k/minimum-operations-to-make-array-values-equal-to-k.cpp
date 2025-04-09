class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int n = nums.size();
        map<int, int> freq;

        // Step 1: Check if any element < k → not possible
        for (int i = 0; i < n; i++) {
            if (nums[i] < k) return -1;
        }

        // Step 2: Build frequency map
        for (int x : nums) {
            freq[x]++;
        }

        // Step 3: Extract unique values ≥ k and sort descending
        vector<int> unique;
        for (auto it : freq) {
            if (it.first >= k) {
                unique.push_back(it.first);
            }
        }

        sort(unique.rbegin(), unique.rend()); // descending order

        int operations = 0;

        // Step 4: Reduce each highest value one-by-one until k
        for (int i = 0; i < unique.size(); i++) {
            if (unique[i] == k) break;
            operations++;
        }

        return operations;
    }
};