class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;

        for(int i=nums2.size()-1; i>=0; i--){
            int val = nums2[i];

            while(!st.empty() and st.top() <= val){
                st.pop();
            }

            if(st.empty()){
                mp[val] = -1;
            }else{
                mp[val] = st.top();
            }

            st.push(val);
        }

        vector<int>ans;
        for(int x : nums1){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};