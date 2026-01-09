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

        TreeNode* node1=root;
        TreeNode* node2=root;

        q.push(root);

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==0){
                    node1 = node;
                }
                if(i==size-1){
                    node2=node;
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }

        if(node1 == node2)return node1;

        return lca(root , node1, node2);
    }

    TreeNode* lca(TreeNode* root , TreeNode* node1, TreeNode* node2){
        if(!root || root==node1 || root==node2)return root;

        TreeNode* left = lca(root->left,node1,node2);
        TreeNode* right = lca(root->right,node1,node2);

        if(left && right) return root;

        if(left)return left;
        return right;
    }
};