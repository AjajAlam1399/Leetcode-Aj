/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> vec;
        fun(root, head, vec);
        ListNode* temp=head;

        for(int i=0;i<vec.size();i++){
            auto it=vec[i];
            temp=head;
            if(check(it,temp))return true;
        }
        return false;
    }

    void fun(TreeNode* root, ListNode*& head, vector<TreeNode*>& vec) {
        if (!root)
            return;
        if (root->val == head->val) {
            vec.push_back(root);
        }
        fun(root->left, head, vec);
        fun(root->right, head, vec);
    }
    bool check(TreeNode* root, ListNode* head) {
        if(!head)return true;
        if(!root) return false;

        if (root->val == head->val) {
            if (check(root->left, head->next)|| 
            check(root->right, head->next)){
                return true;
            }
        }
        return false;
    }
};