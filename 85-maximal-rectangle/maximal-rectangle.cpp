class Solution {
public:

    int helper(vector<int>&heights){
        stack<int>st;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0; i<n; i++){
            while(!st.empty() and heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i - (-1) - 1 : i - st.top() - 1;
                maxArea = max(maxArea, h*width);
            }

            st.push(i);
        }

        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n - (-1) - 1 : n - st.top() - 1;
            maxArea = max(maxArea,h*width);
        }

        return maxArea;
    }

/* matrix = 
[
  [1, 0, 1, 0],
  [1, 1, 1, 1],
  [1, 0, 1, 1]
]
Let's see how heights array will be updated row by row:

Initial heights: [0, 0, 0, 0]
First row ([1, 0, 1, 0]):

heights = [1, 0, 1, 0] // updated based on the first row.
Second row ([1, 1, 1, 1]):

heights = [2, 1, 2, 1] // for each column: 2 continuous 1's in column 0, 1 continuous 1 in column 1, etc.
Third row ([1, 0, 1, 1]):

heights = [3, 0, 3, 2] // continuous 3 1's in column 0, reset column 1, etc.
So, the heights array is used to store the heights of columns for each row as we go row by row, not for each row's maximum height. It treats each row as the base of a histogram and calculates heights for columns across rows.

That’s why we declare heights(cols, 0) because it needs to keep track of column heights for all rows in the matrix.*/

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int>heights(cols,0);
        int maxi = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }
        maxi = max(maxi,helper(heights));//Each row creates a new "histogram" based on the heights array. These histograms represent the heights of continuous 1's in the matrix up to that row. The key point is that the largest rectangle could form before reaching the final row.
        }

        return maxi;

    }
};