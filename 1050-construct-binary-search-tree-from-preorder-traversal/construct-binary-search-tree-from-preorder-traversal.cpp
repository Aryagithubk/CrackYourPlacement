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
    TreeNode* helper(vector<int>&preorder,int &i,int limit){//don't forget to use & with i for pass by reference
        int n = preorder.size();
        if(i == n || preorder[i] > limit){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder,i,root->val);
        root->right = helper(preorder,i,limit);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder,i,INT_MAX);
    }
};