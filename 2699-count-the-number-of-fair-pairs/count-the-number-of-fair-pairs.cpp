#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix each i, and find valid js using binary search
        for (int i = 0; i < n; i++) {
            int minValue = lower - nums[i]; // Minimum value needed in nums[j]
            int maxValue = upper - nums[i]; // Maximum value allowed in nums[j]

            // Step 3: Find first index >= minValue using lower_bound
            int low = lower_bound(nums.begin() + i + 1, nums.end(), minValue) - nums.begin();

            // Step 4: Find first index > maxValue using upper_bound
            int high = upper_bound(nums.begin() + i + 1, nums.end(), maxValue) - nums.begin();

            // Step 5: Count valid js for this i
            count += (high - low);
        }

        return count;
    }
};
