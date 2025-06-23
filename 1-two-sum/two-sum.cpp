class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if((nums[i] + nums[j]) == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int num = target - nums[i];

            if(mp.find(num) != mp.end() and mp[num] != i){
                return {i,mp[num]};
            }
        }

        return {};

    
    }
};