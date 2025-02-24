class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = INT_MIN;
        int left = 0;
        int right = n-1;

        while(left <= right){
            int width = abs(right - left);
            int area = min(height[left],height[right]) * width;
            maxi = max(maxi,area);
            if(height[left] >= height[right]){
               right--;}
               else{
                left++;
               }
        }
        return maxi;
    }
};