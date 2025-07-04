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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxi = 0;

        while(!q.empty()){
            int size = q.size();
            long long norm = q.front().second;

            int first = 0,last = 0;

            for(int i=0; i<size; i++){
                long long ind = q.front().second - norm;//just for avoiding integer overflow
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0){
                    first = ind;
                } 

                if(i == size-1){
                    last = ind;
                }

                if(node->left){
                    q.push({node->left,2*ind + 1});
                }

                if(node->right){
                    q.push({node->right,2*ind + 2});
                }
            }

            maxi = max(maxi,(int)(last-first+1));
        }

        return maxi;
    }
};