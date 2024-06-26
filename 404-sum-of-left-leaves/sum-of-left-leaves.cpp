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
    int sum;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        if(!root){
            return sum;
        }
        fun(root,0);
        return sum;
        
    }
    void fun(TreeNode* root,int sign){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(sign==-1){
                sum+=root->val;
            }
            return;
        }
        fun(root->left,-1);
        fun(root->right,+1);
    }
};