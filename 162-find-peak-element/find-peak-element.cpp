class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        //base cases
        if(n == 1){
            return 0;
        }
        if(arr[0] > arr[1]){
            return 0;
        }//descending order
        if(arr[n-1] > arr[n-2]){
            return n-1;
        }//ascending order

        int s = 1,e = n-2;

        while(s <= e){
            int m = s + (e-s)/2;

            if(arr[m] > arr[m-1] and arr[m] > arr[m+1]){
                return m;
            }
            if(arr[m] > arr[m-1]){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }

        return -1;
    }
};