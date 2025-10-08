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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>map;
        int n=preorder.size();
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }

        return fun(0,n-1,0,n-1,preorder,map);
    }

    TreeNode* fun(int inl,int inr,int prel, int prer,vector<int>& preorder,unordered_map<int,int>&map){

        if(inl==inr){
            return new TreeNode(preorder[inl]);
        }
        if(inl>inr)return NULL;

        TreeNode* root=new TreeNode(preorder[inl]);
        int inroot=map[root->val];
        int len=inroot-prel;
        root->left=fun(inl+1,inl+len,prel,inroot-1,preorder,map);
        root->right=fun(inl+len+1,inr,inroot+1,prer,preorder,map);

        return root;
    }
};