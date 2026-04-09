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
    struct info{
        bool isBST;
        int sum;
        int mini;
        int maxi;
    };

    int maxsum = 0;

    info solve(TreeNode* root){
        if(root == NULL){
            return {true,0,INT_MAX,INT_MIN};
        }

        info left = solve(root->left);
        info right = solve(root->right);

        info curr;

        if(left.isBST and right.isBST and root->val > left.maxi and root->val < right.mini){
            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.mini = min(root->val,left.mini);
            curr.maxi = max(root->val,right.maxi);

            maxsum = max(maxsum,curr.sum);
        }else{
            curr.isBST = false;
            curr.sum = 0;
            curr.mini = INT_MIN;
            curr.maxi = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};