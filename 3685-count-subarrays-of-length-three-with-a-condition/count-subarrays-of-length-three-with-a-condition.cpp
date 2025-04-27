class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        if(n < 3){
            return 0;
        }

        for(int i=0; i<=n-3; i++){
                int first = nums[i];
                int sec = nums[i+1];
                int thir = nums[i+2];

                int sum = first + thir;
                if(sec%2 == 0){
                if(sum == sec/2){
                    count++;
                }
                }
            }

            return count;
    }
};