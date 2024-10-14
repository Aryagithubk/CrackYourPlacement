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

    int maxnum = INT_MIN;

    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int sl = helper(root->left);
        int rl = helper(root->right);

        if(sl < 0){
            sl = 0;
        }

        if(rl < 0){
            rl = 0;
        }


        maxnum = max(maxnum,root->val + sl + rl);

        return root->val + max(sl,rl);

    }
    int maxPathSum(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        helper(root);

        return maxnum;
      
    }
};