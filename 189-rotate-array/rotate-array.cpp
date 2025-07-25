class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k%n;//to avoid runtime error
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};