class Node{
    public:
    char ch;
    Node* children[26];
    Node(char ch){
        this->ch=ch;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};

void update(Node* root,string &str,int &ind){
        if(ind==str.size()){
            return ;
        }

        int i=str[ind]-'a';
        Node* child;
        if(root->children[i]!=NULL){
            child=root->children[i];
        }
        else{
            child=new Node(str[ind]);
            root->children[i]=child;
        }
        ind++;
        update(child,str,ind);
    }
    
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n=words.size();
        Node* root=new Node('\0');
        vector<int>dp(target.size()+1,-1);
        for(int i=0;i<n;i++){
            int ind=0;
            update(root,words[i],ind);
        }
        int ans=fun(0,root,target,dp);
        return ans>=1e5?-1:ans;
    }

    int fun(int ind,Node* root,string &str,vector<int>&dp){

        if(ind==str.size()){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int ans=1e5;
        Node* node=root;
        for(int i=ind;i<str.size();i++){
            int j=str[i]-'a';
            if(node->children[j]==NULL){
                break;
            }
            node=node->children[j];
            int cnt=1+fun(i+1,root,str,dp);
            ans=min(ans,cnt);
        }
        return dp[ind]=ans;
    }
};