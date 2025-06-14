class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>v;
        //storing digits into vector for making process easy
        int num2 = num;
        while(num2 > 0){
            int val = num2%10;
            v.push_back(val);
            num2 = num2/10;
        }

        reverse(v.begin(),v.end());
        vector<int>v2 = v;
        //process of replacing 1st digit and its occurance with 9
        int dig1 = -1;


        for(auto it : v){
            if(it != 9){
                dig1 = it;
                break;
            }
        }

        for(auto &it: v){
            if(it == dig1){
                it = 9;
            }
        }

        //process of changing 1st digit and its occurance with 0
        int dig2 = -1;
        for(auto it : v2){
            if(it != 0){
                dig2 = it;
                break;
            }
        }


        for(auto &it : v2){
            if(it == dig2){
                it = 0;
            }
        }
        int maxval = 0, minval = 0;

        for(auto it : v){
            maxval = maxval * 10 + it;
        }

        for(auto it : v2){
            minval = minval * 10 + it;
        }

        return (maxval - minval);


    }
};