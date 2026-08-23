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
class BSTIterator {

    void pushNext(TreeNode* root , stack<TreeNode*>&st){
        TreeNode* curr = root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
public:

    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushNext(root,st);
    }
    
    int next() {
        TreeNode* node =st.top();
        st.pop();
        pushNext(node->right,st);
        return node->val;
    }

    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */