class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int>st;
        int water = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() and height[i] > height[st.top()]){
                int top = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int dist = i - st.top() - 1;
                int boundheight = min(height[i],height[st.top()]) - height[top];

                water += dist * boundheight;
            }

            st.push(i);
        }

        return water;
    }
};