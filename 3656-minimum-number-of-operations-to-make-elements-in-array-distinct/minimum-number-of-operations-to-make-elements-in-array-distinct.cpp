class Solution {
public:
    bool checkdup(vector<int>&nums){
        int n = nums.size();
        map<int,int>mp;

       for(auto x : nums){
            mp[x]++;
       }

       for(auto x : mp){
        if(x.second > 1){
            return true;
        }
       }

       return false;
    }
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while(checkdup(nums)){
        int n = nums.size();

            if(n <= 3){
                nums.clear();
            }else{
                nums.erase(nums.begin(),nums.begin()+3);
            }
            count++;
        }

        return count;
       
    }
};