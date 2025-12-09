class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long mod = 1e9 + 7;

        unordered_map<int,long long>leftCount, rightCount;
        // hum j ko mid value mangenge toh uske left elements ko leftCount and right values og rightCount me daalenge

        for(int x: nums){
            rightCount[x]++;
        }
        //initially j=0 hai toh bs hume rightCount me right elements daalna hai 

        long long ans = 0;

        for(int j=0; j<nums.size(); j++){
            int mid = nums[j];

            rightCount[mid]--; //remove krdenge iss right element ko kyuki iska use ho gya
            long long target = mid * 2LL;
            long long left_val = leftCount[target];//left side khojenge target ke equal value..leftCount me store h
            long long right_val = rightCount[target];//similarly right side khojenge value jo target ke equal hai
            
            ans = (ans+(left_val*right_val)%mod)%mod;
            leftCount[mid]++;//ab iss j ke value ko left side ka part bna denge by adding in leftCount 
        }

        return ans;
    }
};