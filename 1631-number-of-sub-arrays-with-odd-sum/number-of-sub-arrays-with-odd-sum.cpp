class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int prefix_sum = 0;

        int e_count = 1;
        int o_count = 0;
        int count = 0;
        int mod = 1e9 + 7;

        for(int i=0; i<n; i++){
            prefix_sum = (prefix_sum + arr[i])%mod;

            if(prefix_sum%2 == 0){
                count  = (count + o_count)%mod;
                e_count++;
            }else{
                count = (count + e_count)%mod;
                o_count++;
            }
        }

        return count%mod;
    }
};