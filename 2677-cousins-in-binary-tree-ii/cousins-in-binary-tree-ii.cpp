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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;

        root->val=0;
        q.push(root);
        if(root->left){
            sum+=root->left->val;
        }
        if(root->right){
            sum+=root->right->val;
        }

        while(!q.empty()){
            int n=q.size();
            int currsum=0;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                int csum=0;
                if(it->left){
                    csum+=it->left->val;
                }
                if(it->right){
                    csum+=it->right->val;
                }
                if(it->left){
                    it->left->val=sum-csum;
                    if(it->left->left){
                        currsum+=it->left->left->val;
                    }
                    if(it->left->right){
                        currsum+=it->left->right->val;
                    }
                    q.push(it->left);
                }
                if(it->right){
                    it->right->val=sum-csum;
                    if(it->right->left){
                        currsum+=it->right->left->val;
                    }
                    if(it->right->right){
                        currsum+=it->right->right->val;
                    }
                    q.push(it->right);
                }
            }
            sum=currsum;
        }
        return root;
    }
};