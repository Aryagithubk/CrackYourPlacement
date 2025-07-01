class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0] = 1;//pehle 0 pe 1 allot krliya kyuki jb pehle baar me hi oddcount-k krenge aur 0 aaya toh mp[0] pe kuch rhega hi nhi toh error aa jayega isiliye .
        int count = 0;
        int oddcount = 0;

        for(int i=0; i<n; i++){
            if(nums[i]%2 != 0){
                oddcount++;
            }

            if(mp.find(oddcount-k) != mp.end()){
                count += mp[oddcount-k];//jb hume pta chala ki oddcount-k position pe odd element h iska mtlb uss odd element se abhi tk ke current position tk me sirf k odd elements honge
                //map me ye kaam ho ra ki hum map me oddcount-k position pe jakr dekh re ki kuch hai store ya nhi agar h mtlb koi subarray bn skta h oddcount-k position se current position tk nums array me jisme exact k element honge odd. 
                //toh fir count me add krdenge jitne v numbers store h map me uss position pe kyuki wo ye bta ra ki utne possible sub arrays bn skte h jisme exact k elements ho toh wo total + count hoga. count++ bs ek baar add kr ra jbki aisa possible h ki uss subarrays me v subarray exact k bnaye toh isiliye. 
            }

            mp[oddcount]++;//ye ratt lo ,ye map me oddcount pe increment kr ra kyuki oddcount-k krke aaye toh wo isme help kre ki utne number of subarrays bn skte h wo v oddposition-k se curr elemnt tk.
        }

        return count;
    }

    /*dry run
    eg - 1,1,1,1,1
    k = 3
    mp[0] = 1;//store initially
    i=0,oddcount = 1 -> mp[1] = 1;
    i=1, oddcount = 2 -> mp[2] = 1;
    i = 2,oddcount = 3 -> mp[3] = 1;
    i = 3,oddcount = 4 -> mp[4] = 1;
    i = 4,oddcount = 5 -> mp[5] = 1;

    suppose find wala dekhte h ek case
    at i = 3, if(mp[4-3] got find i.e mp[1]) and mp[1] = 1. means from i=1 to 3 , there is exact 3 odd elements so count = count + mp[1];
    at i = 4, if(mp[5-3]) i.e mp[2] = 1 means from i = 2 to 5 there is one subarray which has exactly 3 elemnts odd.*/
};