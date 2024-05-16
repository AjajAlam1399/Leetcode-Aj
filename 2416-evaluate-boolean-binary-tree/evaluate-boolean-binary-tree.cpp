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
    bool evaluateTree(TreeNode* root) {
        return fun(root);
    }

    bool fun(TreeNode* root){
        if(!root->left  && !root->right){
            return root->val==1;
        }
        bool left=fun(root->left);
        bool right=fun(root->right);

        if(root->val==2)return left|right;
        return left&right;
    }
};