class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int left = 1,right = n-1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(arr[mid-1] < arr[mid] and arr[mid+1] < arr[mid]){
                return mid;
            }else if(arr[mid-1] > arr[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return -1;
    }
};