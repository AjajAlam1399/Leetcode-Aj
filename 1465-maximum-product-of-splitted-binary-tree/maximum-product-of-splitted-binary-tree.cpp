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
    using ll = long long;
    ll sum=0;
    ll ans=0;
    ll mod  = 1e9+7;
public:
    int maxProduct(TreeNode* root) {
        findSum(root);
        fun(root);

        return ans % mod;
    }

    void findSum(TreeNode* root){
        if(!root)return ;
        findSum(root->left);
        findSum(root->right);

        sum+=(ll)root->val;
    }

    ll fun(TreeNode* root){
        if(!root) return 0;

        ll left = fun(root->left);
        ll right = fun(root->right);

        ans = max(ans , left*(sum-left));
        ans = max(ans , right*(sum-right));

        return left+right+root->val;
    }
};