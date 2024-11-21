class Solution {
public:

    int fxn(vector<int>&weights,int val){

        int n = weights.size();
        int days = 0;
        int cal_weights = 0;
        for(int i=0; i<n; i++){
            if(cal_weights + weights[i] <= val){
                cal_weights += weights[i];
            }else{
                days++;
                cal_weights = weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(days > n){
            return -1;
        }

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(fxn(weights,mid) >= days){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low;
    }
};