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
    bool preorder(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){
            return p == q;
        }
        if(p->val != q->val){
            return false;
        }

        bool l = preorder(p->left,q->right);
        bool r = preorder(p->right,q->left);

        if(l==true and r==true) return true;
        return false; 

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return preorder(root->left,root->right);
    }
};