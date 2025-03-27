class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        //algo to find dominant element
        int cand = -1;
        int count = 0;

        for(int i=0; i<n; i++){
            if(count == 0){
                cand = nums[i];
            }

            if(nums[i] == cand){
                count++;
            }else{
                count--;
            }
        }

        //no of dominant element
        int total = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == cand){
                total++;
            }
        }

        //left part me kitne hai usko count krte rhenge aur aise hi move krte rhenge aage aur point pe split krenge arrays ko sub arrays me

        int lefty = 0;

        for(int i=0; i<n-1; i++){//not n cz at last index we cant split
            if(nums[i] == cand){
                lefty++;
            }

            int lsize = i+1;
            int rsize = n - lsize;

            if((lefty * 2 > lsize) and (total - lefty)*2 > rsize){
                return i;
            }
        }

        return -1;
    }
};