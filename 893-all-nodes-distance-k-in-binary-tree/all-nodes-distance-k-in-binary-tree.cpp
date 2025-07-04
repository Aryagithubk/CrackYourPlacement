/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    void helper(TreeNode* root,int k){
        if(!root || k<0) return;
        if(k == 0){
            res.push_back(root->val);
            return;
        }
        helper(root->left,k-1);
        helper(root->right,k-1);
    }
    int dfs(TreeNode* root, TreeNode* target, int k){
       if(!root){
            return -1;
       }
       if(root == target){
        helper(root,k);
        return 0;
       }

       int left = dfs(root->left,target,k);
       if(left != -1){
        if(left + 1 == k){
            res.push_back(root->val);
        }else{
            helper(root->right, k-left-2);
        }

        return left+1;
       }

       int right = dfs(root->right,target,k);
       if(right != -1){
        if(right + 1 == k){
            res.push_back(root->val);
        }else{
            helper(root->left,k-right-2);
        }

        return right+1;
       }
       return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,target,k);
        return res;
    }
};