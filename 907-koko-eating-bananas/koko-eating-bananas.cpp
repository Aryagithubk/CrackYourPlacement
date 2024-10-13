class Solution {
public:

    bool helper(vector<int>&v,long long h,int speed){
        long long count = 0;
        for(int i=0; i<v.size(); i++){
            long long m = v[i]/speed;
            if(v[i]%speed != 0){
                count++;
            }
            count = count + m;
        }

        if(count <= h){
            return true;
        }

        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1,e = *max_element(piles.begin(),piles.end());
        int ans = -1;
        long long ho = h;

        while(s<= e){
            int m = s+(e-s)/2;

            if(helper(piles,ho,m) == true){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }

        return ans;
    }
};