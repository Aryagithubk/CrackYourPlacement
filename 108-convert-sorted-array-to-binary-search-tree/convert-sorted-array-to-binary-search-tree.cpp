/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* makeBST(vector<int>&nums,int start,int end){
        if(start > end){
            return nullptr;
        }

        int mid = start + (end - start)/2;
        //hum mid nikal re kyuki mid ko root bnayenge aur fir left right me v jake mid lenge aur usko root bnate jayenge isse hume balanced tree milga kyuki hum mid nikal re mtlb do equal sub part me divide kr re toh automatic bnega balanced.
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = makeBST(nums,start,mid-1);
        node->right = makeBST(nums,mid+1,end);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
    }

};