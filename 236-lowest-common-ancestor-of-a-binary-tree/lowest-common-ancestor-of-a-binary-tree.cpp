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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root,p,q);
    }

    TreeNode* fun(TreeNode* root , TreeNode* p ,TreeNode* q){
        if(!root || root->val==p->val || root->val==q->val)return root;

        TreeNode* l=fun(root->left,p,q);
        TreeNode* r = fun(root->right,p,q);

        if(l && r)return root;
        if(l)return l;
        return r;
    }
};