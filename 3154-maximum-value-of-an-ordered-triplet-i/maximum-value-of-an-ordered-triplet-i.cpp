class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
    long long maxVal = 0; // We initialize with 0 since we return 0 if all values are negative.

    for (int i = 0; i < n - 2; i++) {   // First index
        for (int j = i + 1; j < n - 1; j++) {  // Second index
            for (int k = j + 1; k < n; k++) {  // Third index
                long long value = (long long)(nums[i] - nums[j]) * nums[k];
                maxVal = max(maxVal, value);
            }
        }
    }
    return maxVal;
    }
};