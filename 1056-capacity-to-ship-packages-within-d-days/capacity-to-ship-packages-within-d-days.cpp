class Solution {
public:

    int ispossible(vector<int>&weights,int capacity){
        int day = 1;
        int load = 0;

        int n = weights.size();

        for(int i=0; i<n; i++){
            if(load + weights[i] > capacity){
                day += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }

        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(ispossible(weights,mid) <= days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};