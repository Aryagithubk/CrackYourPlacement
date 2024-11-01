class Solution {
public:

    vector<int> merge(vector<int>&nums1,vector<int>&nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0;
        int high = 0;
        vector<int>arr;

        while(low < n1 and high < n2){
            if(nums1[low] <= nums2[high]){
                arr.push_back(nums1[low]);
                low++;
            }else{
                arr.push_back(nums2[high]);
                high++;
            }
        }

        while(low < n1){
            arr.push_back(nums1[low]);
            low++;
        }

        while(high < n2){
            arr.push_back(nums2[high]);
            high++;
        }

        return arr;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp = merge(nums1,nums2);

        int n = temp.size();
        double med = 0;

        if(n%2 == 0){
            double avg = temp[n/2] + temp[n/2 - 1];
            med = avg/2;
        }else{
            med = temp[n/2];
        }


        return med;

    }
};