class Solution {
public:
    int helper(vector<int>&height){
        int n = height.size();
        stack<int>st;
        vector<int>leftsmall;
        vector<int>rightsmall;

        for(int i=0; i<n; i++){
            while(!st.empty() and height[st.top()] >= height[i]){
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
            while(!st.empty() and height[st.top()] >= height[i]){
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
        int maxiarea = 0;
        for(int i=0; i<n; i++){
            maxiarea = max(maxiarea, height[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return maxiarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>height(col,0);
        int area = INT_MIN;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int maxiarea = helper(height);
            area = max(area,maxiarea);
        }

        return area;
    }
};