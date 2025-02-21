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
class FindElements {
    queue<pair<TreeNode*,int>>q;
    unordered_set<int>set;
public:
    FindElements(TreeNode* root) {
        if(root){
            q.push({root,0});
            set.insert(0);

            while(!q.empty()){
                auto it =q.front();
                auto node=it.first;
                auto no=it.second;
                q.pop();

                if(node->left){
                    q.push({node->left,2*no+1});
                    set.insert(2*no+1);
                }
                if(node->right){
                    q.push({node->right,2*no+2});
                    set.insert(2*no+2);
                }
            }
        }
    }
    
    bool find(int target) {
        return set.find(target)!=set.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */