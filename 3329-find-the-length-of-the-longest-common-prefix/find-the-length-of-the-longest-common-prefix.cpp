class Node{
    public:
    char data;
    Node* children[10];
    bool isTerminal;
    Node(char ch){
        this->data=ch;
        for(int i=0;i<10;i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root= new Node('\0');
    }
    void update(Node* root,string str){

        if(str.size()==0){
            root->isTerminal=true;
            return ;
        }
        int ind=str[0]-'0';
        Node* child=NULL;
        if(root->children[ind]!=NULL){
            child=root->children[ind];
        }
        else{
            child=new Node(str[0]);
            root->children[ind]=child;
        }
        update(child,str.substr(1));
    }
    void search(Node* root,string str,int &cnt){
        if(str.size()==0){
            return ;
        }
        int ind=str[0]-'0';
        Node * child;
        if(root->children[ind]!=NULL){
            cnt++;
            search(root->children[ind],str.substr(1),cnt);
        }
        return ;
    }
    public:
    void trieUpdate(string str){
        update(root,str);
    }
    int trieSearch(string str){
        int cnt=0;
        search(root,str,cnt);
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie obj;
        for(int i=0;i<arr1.size();i++){
            string str=to_string(arr1[i]);
            obj.trieUpdate(str);
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            string str=to_string(arr2[i]);
            ans=max(ans,obj.trieSearch(str));
        }
        return ans;
    }
};