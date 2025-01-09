class Node{
    public:
    Node* children[26];
    int cnt;
    char ch;
    Node(char ch){
        this->cnt=1;
        this->ch=ch;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};
class Trie{
    private:
    Node * root;
    void insertTrie(Node* root,string str){

        if(str.size()==0){
            return;
        }

        int ind=str[0]-'a';
        Node* child;
        if(root->children[ind]){
            root->children[ind]->cnt++;
            child=root->children[ind];
        }
        else{
            child=new Node(str[0]);
            root->children[ind]=child;
        }
        insertTrie(child,str.substr(1));
    }
    int searchTrie(Node* root,string str){
        int ind=str[0]-'a';
        if(str.size()==1){
            if(root->children[ind]){
                return root->children[ind]->cnt;
            }
            else{
                return 0;
            }
        }

        Node* child;
        if(root->children[ind]){
            child=root->children[ind];
        }
        else{
            return 0;
        }
        return searchTrie(child,str.substr(1));
    }
    public:
    Trie(){
        root=new Node('\0');
    }
    void insert(string str){
        insertTrie(root,str);
    }
    int search(string str){
        return searchTrie(root,str);
    }

};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie tr;
        for(int i=0;i<words.size();i++){
            tr.insert(words[i]);
        }
        return tr.search(pref);
    }
};