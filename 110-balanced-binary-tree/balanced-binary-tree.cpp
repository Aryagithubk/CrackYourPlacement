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

    int maxHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = maxHeight(root->left);
        int r = maxHeight(root->right);

        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int l = maxHeight(root->left);
        int r = maxHeight(root->right);

        if(abs(l-r) > 1){
            return false;
        }

        bool le = isBalanced(root->left);
        bool ri = isBalanced(root->right);

        return le and ri;

    }
};