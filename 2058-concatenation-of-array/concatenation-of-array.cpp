class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0; i<2*nums.size(); i++){
            ans.push_back(nums[i%n]);
        }
        return ans;
    }
};