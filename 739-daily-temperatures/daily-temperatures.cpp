class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>v(n,0);
        stack<int>st;

        for(int i=0; i<n; i++){
            
            while(!st.empty() and temperatures[st.top()] < temperatures[i]){
                int first = st.top();
                st.pop();

                v[first] = i - first;
            }

            st.push(i);
        }

        return v;
    }
};