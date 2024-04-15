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
    long long ans;
public:
    int sumNumbers(TreeNode* root) {
        ans=0;
        fun(root,0);
        return ans;
    }
    
    void fun(TreeNode* root,long long sum){
        if(!root)return;
        if(!root->left && !root->right){
            
            ans+=sum*10+root->val;
            return;
        }        
        fun(root->left,sum*10+root->val);
        fun(root->right,sum*10+root->val);
        return;
    }
};