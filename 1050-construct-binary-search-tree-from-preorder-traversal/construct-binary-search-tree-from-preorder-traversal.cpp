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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind =0;
        return fun(ind,-1e9,1e9,preorder);
    }

    TreeNode* fun(int &ind ,int lVal ,int rVal , vector<int>& preorder){

        if(ind==preorder.size() ||  preorder[ind]<lVal || preorder[ind]>rVal){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = fun(ind , lVal,root->val,preorder);
        root->right = fun(ind,root->val,rVal,preorder);

        return root;
    }
};