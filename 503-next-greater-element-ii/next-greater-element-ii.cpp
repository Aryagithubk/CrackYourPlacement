class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,-1);
        stack<int>st;

        for(int i=0; i<2*n; i++){

            while(!st.empty() and nums[st.top()] < nums[i%n]){
                int first = st.top();
                st.pop();
                v[first] = nums[i%n];
            }
            st.push(i%n);

        }

        return v;
    }
};