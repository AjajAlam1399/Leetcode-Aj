/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)return {};
        vector<int>ans;
        fun(root,ans);
        ans.push_back(root->val);
        return ans;
    }
    void fun(Node* root,vector<int>&ans){
        if(root->children.size()==0)return;
        for(auto it:root->children){
            fun(it,ans);
            ans.push_back(it->val);
        }
    }
};