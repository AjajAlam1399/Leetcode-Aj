
class DSU{
    vector<int>parent;
    vector<int>size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void groupBySize(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(size[rootx]>=size[rooty]){
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
        else{
            parent[rootx]=rooty;
            size[rooty]+=size[rootx];  
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DSU ds(1001);

        for(auto edge:edges){
            int rootx=ds.find(edge[0]);
            int rooty=ds.find(edge[1]);
            if(rootx==rooty){
                return {edge[0],edge[1]};
            }
            ds.groupBySize(edge[0],edge[1]);
        }
        return {};

    }
};