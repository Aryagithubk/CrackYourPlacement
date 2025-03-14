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
 //iterative way

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;

        if(root == NULL){
            return v;
        }
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* tp = st.top();
            st.pop();

            v.push_back(tp->val);
            if(tp->right != NULL){
                st.push(tp->right);
            }
            if(tp->left != NULL){
                st.push(tp->left);
            }

        }
        return v;
    }
};