class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;

        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<n; i++){
               bool res = false;
            for(int j=0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    for(int k=j+1; k<m; k++){
                        if(nums2[k] > nums1[i]){
                            v.push_back(nums2[k]);
                            res = true;
                            break;
                        }
                    }
                         if(res == false){
                             v.push_back(-1);
                         }
                }
            }
        }


        return v;
    }
};