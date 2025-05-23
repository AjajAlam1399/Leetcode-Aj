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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        queue<TreeNode*>q;

        q.push(root);
        TreeNode* L=NULL;
        TreeNode* R=NULL;



        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(i==0)L=node;
                if(i==size-1)R=node;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }

        return fun(root,L,R);
    }

    TreeNode* fun(TreeNode* root,TreeNode* l,TreeNode* r){
        if(!root ||root==l || root==r)return root;

        auto left=fun(root->left,l,r);
        auto right=fun(root->right,l,r);

        if(left && right)return root;
        if(!left)return right;
        return left;
    }
};