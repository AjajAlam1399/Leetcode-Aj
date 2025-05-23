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

    class ST{
        int n,maxD;
        vector<vector<int>>st;

        public:
        ST(int n){
            this->n=n;
            maxD=log2(n)+1;
            st.resize(n,vector<int>(maxD,0));
        }
        void build(vector<int>&nums){

            for(int i=n-1;i>=0;i--){
                for(int j=0;j<maxD;j++){
                    if(i+(1<<j)-1>=n)break;
                    if(!j){
                        st[i][j]=nums[i];
                    }
                    else{
                        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
                    }
                }
            }
        }

        int query(int l,int r){
            int dis=r-l+1;
            int j=log2(dis);
            return max(st[l][j],st[r-(1<<j)+1][j]);
        }
    };
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();

        ST st(n);
        st.build(nums);

        for(int i=0;i<n;i++){
            map[nums[i]]=i;
        }

        return fun(0,n-1,map,st);
    }

    TreeNode* fun(int l,int r, unordered_map<int,int>&map, ST &st){

        if(l>r){
            return NULL;
        }
        int val=st.query(l,r);
        int ind=map[val];
        TreeNode* root=new TreeNode(val);
        root->left=fun(l,ind-1,map,st);
        root->right=fun(ind+1,r,map,st);

        return root;
    }
};