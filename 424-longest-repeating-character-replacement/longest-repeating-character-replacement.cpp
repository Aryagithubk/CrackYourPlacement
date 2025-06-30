class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        int ans = 0;
        vector<int>freq(26,0);
        //first we are making freq vector from 1 to 16 so that we can know which letter has highest frequency and we will convert other character into that max freq character
        for(int right=0; right<n; right++){
            freq[s[right] - 'A']++;

            //while adding freq we will also update the maxicount of most frequent character bcz we just need count of most frequent character at last.

            maxi = max(maxi,freq[s[right] - 'A']);
            while((right-left+1) - maxi > k){
                //then window size - most frequent character will give how many character we can change and also if it is less than k
                //if > k then shrink window size from left and also decrease frequency of that index which obv present on left index.
                freq[s[left] - 'A']--;
                left++;
            }

            //also we have to take max of all these too,cz we have to return longest substring.

            ans = max(ans,right-left+1);
        }

        return ans;
    }
};