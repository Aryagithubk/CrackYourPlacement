class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++){
        //     ans = ans^nums[i];
        // }
        // return ans;
        int n = arr.size();

        if(n == 1){
            return arr[0];
        }
        if(arr[0] != arr[1]){
            return arr[0];
        }
        if(arr[n-1] != arr[n-2]){
            return arr[n-1];
        }
        int s = 1,e = n-2;


        while(s <= e){
            int m = s + (e-s)/2;

            if(arr[m] != arr[m-1] and arr[m] != arr[m+1]){
                return arr[m];
            }

            if(m%2 == 1 and arr[m] == arr[m-1] || m%2 == 0 and arr[m] == arr[m+1]){
                s = m+1;
            }else{
                e = m-1;
            }
        }

        return -1;
    }
};