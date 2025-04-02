class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        vector<int>maxLeft(n,0);//to store max ele of left side of nums[j]

        maxLeft[0] = nums[0];
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1],nums[i]);
        }

        vector<int>maxRight(n,0);//to store max ele of right side of nums[j]

        maxRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1],nums[i]);
        }

        //ab hum nums[j] ke sath left aur right ko use krke dekhenge max val

        long long maxi = 0;

        for(int j=1; j<n-1; j++){
            long long left = maxLeft[j-1];
            long long right = maxRight[j+1];

            if(left > nums[j]){
                long long val = (left - nums[j]) * right;
                maxi = max(maxi,val);

            }
        }

        return maxi;

    }
};