class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int evensum = 0;
        int oddsum = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                evensum += nums[i];
            }else{
                oddsum += nums[i];
            }
        }

        int counteven = 0, countodd = 0;

        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                evensum -= nums[i];
            }else{
                oddsum -= nums[i];
            }

            if(oddsum + counteven == evensum + countodd){
                count++;
            }

            if(i%2 == 0){
                counteven += nums[i];
            }else{
                countodd += nums[i];
            }
        }
       return count;
      
    }
};