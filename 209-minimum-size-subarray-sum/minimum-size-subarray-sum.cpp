class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    //     int mini = INT_MAX;
    //     for(int i=0; i<nums.size(); i++){
    //         int sum = 0;
    //         for(int j=i; j<nums.size(); j++){
    //             sum += nums[j];
    //             if(sum >= target){
    //                 mini = min(mini,j-i+1);
    //             }
    //         }
    //     }

    //     if(mini == INT_MAX){
    //         return 0;
    //     }

    //     return mini;
    // }

    int left = 0;
    int n = nums.size();
    int mini = INT_MAX;
    int sum = 0;

    for(int right = 0; right<n; right++){
        sum += nums[right];

        while(sum >= target){
            mini = min(mini,right-left+1);
            sum -= nums[left];
            left++;
        }
    }

    if(mini == INT_MAX){
        return 0;
    }

    return mini;
    }
    
};