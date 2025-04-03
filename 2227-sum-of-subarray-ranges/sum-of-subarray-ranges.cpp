class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;

        vector<int>prevGre(n,-1);//finding prev greater ele
        for(int i= n-1; i>=0; i--){
            while(!s.empty() and nums[s.top()] <= nums[i]){
                prevGre[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) s.pop();//for performing for next operation

        vector<int>nextGre(n,n);//to find next greater ele
        for(int i=0; i<n; i++){
            while(!s.empty() and nums[s.top()] < nums[i]){
                nextGre[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) s.pop();

        vector<int>nextSma(n,n);
        //to find next smaller element

        for(int i=0; i<n; i++){
            while(!s.empty() and nums[s.top()] > nums[i]){
                nextSma[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        while(!s.empty()) s.pop();

        vector<int>prevSma(n,-1);

        for(int i=n-1; i>=0; i--){
            while(!s.empty() and nums[s.top()] >= nums[i]){
                prevSma[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        long long maxi = 0, mini = 0;

        for(int i=0; i<n; i++){
            long long maxContri = (long long)(i - prevGre[i]) * (nextGre[i] - i);
            long long minContri = (long long)(i - prevSma[i]) * (nextSma[i] - i);

            maxi += maxContri * nums[i];
            mini += minContri * nums[i];
        }

        return maxi - mini;

    }
};