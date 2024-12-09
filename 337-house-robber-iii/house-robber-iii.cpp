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
    int rob(TreeNode* root) {
        vector<int>ans=fun(root);

        return max(ans[0],ans[1]);
    }

    vector<int> fun(TreeNode* root){
        if(!root){
            return {0,0};
        }

        vector<int>left=fun(root->left);
        vector<int>right=fun(root->right);

        int rootInclude=root->val + left[1]+right[1];
        int notRoot=max(left[0],left[1])+max(right[0],right[1]);

        return {rootInclude,notRoot};
    }
};