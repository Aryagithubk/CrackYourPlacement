class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> result;
        int n = nums.size();
        
        // XOR of all elements in nums
        int currentXOR = 0;
        
        // Compute the XOR of all numbers first
        for(int i = 0; i < n; i++) {
            currentXOR ^= nums[i];
        }
        
        // Max value with maximumBit bits is (2^maximumBit - 1)
        int maxVal = (1 << maximumBit) - 1;
        
        // Now process each query from last to first
        for(int i = 0; i < n; i++) {
            result.push_back(currentXOR ^ maxVal);  // Maximum XOR for the current query
            currentXOR ^= nums[n - 1 - i];          // Remove the last element from XOR kyuki 
            // agar last element ko firse xor kr denge toh last xor last zero ho jayega
        }
        
        return result;
    }
};
