class DisJointSet{
    private:
    vector<int>parent;
    vector<int>size;
    vector<int>rank;

    public:
    DisJointSet(int v){
        parent.resize(v);
        size.resize(v);
        rank.resize(v);
        for(int i=0;i<v;i++)parent[i]=i;
    }
    int findParent(int v){
        if(parent[v]==v){
        return parent[v];
        }
            return parent[v]=findParent(parent[v]);
    }

    void groupBySize(int x,int y){
        int rootx=findParent(x);
        int rooty=findParent(y);
         if(rootx==rooty){
            return ;
        }
        if(size[rootx]<size[rooty]){
            parent[rootx]=rooty;
            size[rooty]+=size[rootx];
        }
        else{
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
    }
    void groupByRank(int x,int y){
        int rootx=findParent(x);
        int rooty=findParent(y);
         if(rootx==rooty){
            return ;
        }
        if(rank[rootx]<rank[rooty]){
            parent[rootx]=rooty;
        }
        else{
            parent[rooty]=rootx;
            if(rank[rootx]==rank[rooty]){
                rank[rootx]++;
            }
        }
    }

};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        DisJointSet ds(row*col+1);

        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    int arr1[]={-1,0,1,0};
                    int arr2[]={0,-1,0,1};
                    for(int dir=0;dir<4;dir++){
                        int newi=i+arr1[dir];
                        int newj=j+arr2[dir];
                        if(newi>=0 && newj>=0 && newi<row && newj<col && grid[newi][newj]=='1'){
                            int ind1=col*i+j;
                            int ind2=col*newi+newj;
                            ds.groupByRank(ind1,ind2);
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' ){
                    int ind=col*i+j;
                    if(ds.findParent(ind)==ind){
                        cnt++;
                    }
                }
            }
            // cout<<endl;
        }

        return cnt;
    }
};