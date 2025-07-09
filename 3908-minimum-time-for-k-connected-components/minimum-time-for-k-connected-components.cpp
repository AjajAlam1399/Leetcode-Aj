
class Dsu{
    public:
    vector<int>parent;
    vector<int>size;
    int n;

    Dsu(int n){
        this->n=n;
        parent.resize(n,-1);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void groupBySize(int x,int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx==rooty){
            return ;
        }

        if(size[rootx]<size[rooty]){
            parent[rooty]=rootx;
            size[rootx]+=rooty;
        }
        else{
            parent[rootx]=rooty;
            size[rooty]+=rootx;
        }
    }

    int findAns(){
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int e=0;
        Dsu pa(n);
        
        for(int i=0;i<edges.size();i++){
            e=max(e,edges[i][2]);
            pa.groupBySize(edges[i][0],edges[i][1]);
        }
        if(pa.findAns()>=k)return 0;
        int s=0;
        int ans=e;
        while(s<=e){
            Dsu ds(n);
            int mid=(s+e)/2;

            for(auto it :edges){
                if(it[2]>mid){
                    auto u=it[0];
                    auto v=it[1];
                    ds.groupBySize(it[0],it[1]);
                }
            }
            int currans=ds.findAns();
            if(currans>=k){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};