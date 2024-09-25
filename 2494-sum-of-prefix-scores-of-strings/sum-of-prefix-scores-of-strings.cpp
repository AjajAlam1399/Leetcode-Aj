class Node{
    public:
    long long cnt;
    char ch;
    Node* children[26];
    Node(char ch){
        this->cnt=1;
        this->ch=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class Trie{
    Node* root;

    void trieUpdate(Node* root,string &str,int &i){

        if(i==str.size())return;

        int ind=str[i]-'a';
        Node* child;
        if(root->children[ind]!=NULL){
            root->children[ind]->cnt++;
            child=root->children[ind];
        }
        else{
            child=new Node(str[i]);
            root->children[ind]=child;
        }
        i++;
        trieUpdate(child,str,i);
    }
    void trieSearch(Node* root,string &str,long long &cnt,int &i){
        if(str.size()==i)return;
        int ind=str[i]-'a';
        if(root->children[ind]!=NULL){
           cnt+=root->children[ind]->cnt;
           i++;
            trieSearch(root->children[ind],str,cnt,i);
        }
        return;
    }
    public:
    Trie(){
        root=new Node('\0');
    }
    void update(string str){
        int ind=0;
        trieUpdate(root,str,ind);
    }
    int search(string str){
        long long cnt=0;
        int ind=0;
        trieSearch(root,str,cnt,ind);
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();

        Trie obj;

        for(int i=0;i<n;i++){
            obj.update(words[i]);
        }
        vector<int>ans;

        for(int i=0;i<n;i++){
            int subans=obj.search(words[i]);
            ans.push_back(subans);
        }

        return ans;
    }
};