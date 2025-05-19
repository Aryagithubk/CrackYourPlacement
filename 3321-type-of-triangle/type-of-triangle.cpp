class Solution {
public:
    string triangleType(vector<int>& nums) {
        for(int i = 0; i <= nums.size() - 3; i++) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];

            
            if(a + b <= c || a + c <= b || b + c <= a) {
                continue;  
            }

            if(a == b && b == c) {
                return "equilateral";
            }
            if(a == b || b == c || a == c) {
                return "isosceles";
            }
            return "scalene";  
        }

        return "none"; 
    }
};
