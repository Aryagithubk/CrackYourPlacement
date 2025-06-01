class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>leftsmall;
        vector<int>rightsmall;

        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmall.push_back(0);
            }else{
                leftsmall.push_back(st.top()+1);
            }
            st.push(i);
        }

        //clearing stack for reuse
        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()] > heights[i] ){
                st.pop();
            }

            if(st.empty()){
                rightsmall.push_back(n-1);
            }else{
                rightsmall.push_back(st.top()-1);
            }

            st.push(i);
        }

        reverse(rightsmall.begin(),rightsmall.end());

        int maxi_area = 0;
        for(int i=0; i<n; i++){
            maxi_area = max(maxi_area, heights[i]*(rightsmall[i] - leftsmall[i] + 1));
        }

        return maxi_area;
    }
};