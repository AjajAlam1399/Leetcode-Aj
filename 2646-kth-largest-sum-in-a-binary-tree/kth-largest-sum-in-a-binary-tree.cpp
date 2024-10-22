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
    using ll=long long;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            ll sum=0;
            ll n=q.size();
            for(ll i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                sum+=it->val;
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            if(pq.size()<k){
                pq.push(sum);
            }
            else{
                if(pq.top()<sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        return pq.size()==k?pq.top():-1;
    }
};