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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            vector<int>level;

            for(int i=0; i<sz; i++){
            TreeNode* tp = q.front();
            q.pop();

            if(tp->left != NULL){
                q.push(tp->left);
            }
            if(tp->right != NULL){
                q.push(tp->right);
            }

            level.push_back(tp->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};