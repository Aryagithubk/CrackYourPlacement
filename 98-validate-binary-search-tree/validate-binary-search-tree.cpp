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
    bool helper(TreeNode* root,long long leftLimit, long long rightLimit){
        if(!root){
            return true;
        }
        if(root->val >= rightLimit || root->val <= leftLimit){
            return false;
        }
        return (helper(root->left,leftLimit,root->val) and helper(root->right,root->val,rightLimit));
    }
    bool isValidBST(TreeNode* root) {
       
        bool res = helper(root,LLONG_MIN,LLONG_MAX);
        return res;

    }
};