class Solution {
public:

    int ispossible(vector<int>&nums,int val){
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += ceil((double)(nums[i])/(double)(val));;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int n = nums.size();

        if(n > threshold){
            return -1;
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            if(ispossible(nums,mid) <= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};