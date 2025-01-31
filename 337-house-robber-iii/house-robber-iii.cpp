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
        unordered_map<TreeNode*,int>dp;
    int rob(TreeNode* root) {
        if(!root){//when no node is present
            return 0;
        }

        //hume tree nodes store krne h dp me isiliye hum vector use nhi kr skte kyuki wo sequence wise store krte h value but ye continuous allocate nhi hota,it has pointers jo order me nhi hote
        if(dp.find(root) != dp.end()){
            return dp[root];
        }

        //two cases if we skip root node and rob child node or rob root node skip its child node
        //rob root node
        int rootval = root->val;
        if(root->left){
            rootval += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            rootval += rob(root->right->left) +rob(root->right->right);
        }

        //rob children node

        int childnode = rob(root->left) + rob(root->right);

        return dp[root] = max(rootval,childnode);
        
    }
};