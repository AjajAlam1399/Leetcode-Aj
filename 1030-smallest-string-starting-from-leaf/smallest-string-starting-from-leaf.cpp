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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        fun(root,"",ans);
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
    void fun(TreeNode* root,string subans,string &ans){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            subans.push_back('a'+root->val);
            // cout<<ans<<" "<<subans<<endl;
            if(ans.size()==0){
                ans=subans;
            }
            else{
                int i=ans.size()-1;
                int j=subans.size()-1;
                bool flag=false;
                // cout<<ans<<" "<<subans<<endl;
                while(i>=0 && j>=0){
                    // cout<<i<<" "<<j<<endl;
                    if(ans[i]>subans[j]){
                        ans=subans;
                        flag=true;
                        break;
                    }
                    else if(ans[i]<subans[j]){
                        flag=true;
                        // cout<<"hi"<<endl;
                        break;
                    }

                    i--;
                    j--;
                }

                if(!flag){
                    if(i!=-1){
                        ans=subans;
                    }
                }
            }
            subans.pop_back();
            return;
        }
        subans.push_back('a'+root->val);
        fun(root->left,subans,ans);
        fun(root->right,subans,ans);
        subans.pop_back();

    }
};