class Solution {
public:

    bool possible(vector<int>&bloomDay,int m,int k,int mid){
        int n = bloomDay.size();
        int cnt = 0;
        int boque = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else{
                boque += cnt/k;
                cnt = 0;
            }
        }

        boque = boque + cnt/k;
        if(boque >= m){
            return true;
        }else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        long long val = m * 1ll *k * 1ll;

        if(val > n){
            return -1;
        }

        for(int i=0; i<n; i++){
            maxi = max(maxi,bloomDay[i]);
            mini = min(mini,bloomDay[i]);
        }
        int s = mini;
        int e = maxi;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(possible(bloomDay,m,k,mid) == true){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return s;
    }
};