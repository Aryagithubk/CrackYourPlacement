class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right=  n-1;
        int maxiryt = 0, maxileft = 0;
        int ans = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > maxileft){
                    maxileft = max(maxileft,height[left]);
                }else{
                    ans += (maxileft - height[left]);
                }

                left++;
            }
            else if(height[right] < height[left]){
                if(height[right] > maxiryt){
                    maxiryt = max(maxiryt,height[right]);
                }else{
                    ans += (maxiryt - height[right]);
                }
            right--;
            }
        }

        return ans;
    }
};