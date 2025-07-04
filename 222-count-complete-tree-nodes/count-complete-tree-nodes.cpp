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
    int helper1(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int height = 0;

        while(root != NULL){
            height++;
            root = root->left;
        }

        return height;
    }

    int helper2(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int height = 0;
        while(root != NULL){
            height++;
            root = root->right;
        }

        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int lh = helper1(root->left);
        int rh = helper2(root->right);

        if(lh == rh){
            return (1 << (lh + 1)) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};