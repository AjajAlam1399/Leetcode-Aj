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
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);
    }
    vector<TreeNode*> fun(int l,int r){

        if(l>r){
            return {NULL};
        }
        
        vector<TreeNode*>ans;

        for(int i=l;i<=r;i++){
            vector<TreeNode*> le=fun(l,i-1);
            vector<TreeNode*> ri=fun(i+1,r);

            for(auto leftnode:le){
                for(auto rightnode:ri){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftnode;
                    root->right=rightnode;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};