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
    long long sum;
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        fun(root);
        return root;
    }
    void fun(TreeNode* root){
        if(!root){
            return ;
        }
        fun(root->right);
        int temp=root->val;
        root->val+=sum;
        sum+=temp;
        fun(root->left);
    }
};