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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(isLeaf(root,target))return NULL;
        fun(root,target);
        if(isLeaf(root,target))return NULL;
        return root;
    }

    bool isLeaf(TreeNode* root, int target){
        if(!root->left && ! root->right && root->val==target)return true;
        return false;
    }

    void fun(TreeNode* root,int &target){
        if(!root)return ;

        if(root->left && isLeaf(root->left,target)){
            root->left=NULL;
        }
        if(root->right && isLeaf(root->right,target)){
            root->right=NULL;
        }
        fun(root->left,target);
        fun(root->right,target);

        if(root && root->left && isLeaf(root->left,target)){
            root->left=NULL;
        }
        if(root &&root->right && isLeaf(root->right,target)){
            root->right=NULL;
        }
    }
};