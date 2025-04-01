class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;
        stack<int>st;

        vector<int>prevless(n,-1);
        vector<int>nextless(n,n);

        //ple
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]){
                st.pop();
            }

            prevless[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }

        while(!st.empty()){
            st.pop();//doing so that we can perform for nle also
        }

        //nle
        for(int i = n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                st.pop();
            }

            nextless[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        //contributation

        long long res = 0;
        for(int i=0; i<n; i++){
            long long left = i - prevless[i];
            long long right = nextless[i] - i;
            res = (res + (arr[i] * left * right)% MOD)% MOD;
        }

        return res;
    }
};