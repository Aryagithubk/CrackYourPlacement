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
    bool valid(TreeNode* root,long mini,long maxi){
        if(root == NULL){
            return true;
        }
        if(!(root->val > mini and root->val < maxi)){
            return false;
        }

        return valid(root->left,mini,root->val) and valid(root->right,root->val,maxi);

    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN,LONG_MAX);
    }
};