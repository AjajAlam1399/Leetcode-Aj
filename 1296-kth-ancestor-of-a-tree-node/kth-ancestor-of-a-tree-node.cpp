class TreeAncestor {
    int blArr[5*10000+1][21];
    void build(int node,int parent,vector<vector<int>>&tree){
        blArr[node][0]=parent;
        for(int i=1;i<21;i++){
            if(blArr[node][i-1]!=-1){
                blArr[node][i]=blArr[blArr[node][i-1]][i-1];
            }
            else{
                blArr[node][i]=-1;
            }
        }
        for(auto adjnode:tree[node]){
            if(adjnode!=parent){
                build(adjnode,node,tree);
            }
        }
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>>tree(n);
        for(int i=1;i<n;i++){
            tree[parent[i]].push_back(i);
        }
        build(0,-1,tree);
    }
    
    int getKthAncestor(int node, int k) {
        if(node==-1 || k==0){
            return node;
        }

        for(int i=20;i>=0;i--){
            if(k>=(1<<i)){
                return getKthAncestor(blArr[node][i],
                k-(1<<i));
            }
        }
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */