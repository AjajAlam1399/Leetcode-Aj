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
    TreeNode* recoverFromPreorder(string tra) {
        stack<pair<TreeNode*,int>>st;
        int i=0,n=tra.size();
        int level=0,value=0;
        TreeNode* head=NULL;
        while(i<n){
            if(tra[i]=='-'){
                while(i<n && tra[i]=='-'){
                    level++;
                    i++;
                }
            }
            else{
                while(i<n && tra[i]>='0' && tra[i]<='9' ){
                    value*=10;
                    value+=tra[i]-'0';
                    i++;
                }
            }
            if(level>=0 && value>0){
                TreeNode* newNode=new TreeNode(value);
                if(!head){
                    head=newNode;
                }
                if(st.empty()){
                    st.push({newNode,1});
                }
                else{
                    if(st.top().second==level){
                        st.top().first->left=newNode;
                        st.push({newNode,st.top().second+1});
                    }
                    else{
                        while(!st.empty() && st.top().second!=level){
                            st.pop();
                        }
                        auto top=st.top();
                        st.pop();
                        top.first->right=newNode;
                        st.push({newNode,top.second+1});
                    }
                }
                level=0;
                value=0;
            }
        }
        return head;
    }
};