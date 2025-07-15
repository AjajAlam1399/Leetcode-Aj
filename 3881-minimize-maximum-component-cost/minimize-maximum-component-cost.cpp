class DS{
    public:
    int n;
    vector<int>parent,size;

    DS(int n){
        this->n=n;
        parent.resize(n,0);
        size.resize(n,1);

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
            parent[rootx]=rooty;
            size[rooty]+=size[rootx];
        }
        else{
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
    }

    int findAns(){
        int ans=0;

        for(int i=0;i<n;i++){
            if(parent[i]==i)ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int e=0,s=0;
        int n2=edges.size();

        for(int i=0;i<n2;i++){
            e=max(e,edges[i][2]);
        }

        int currans=e;

        while(s<=e){
            int mid=(s+e)/2;
            DS ds(n);

            for(int i=0;i<n2;i++){
                int u=edges[i][0];
                int v=edges[i][1];
                int w=edges[i][2];

                if(w<=mid){
                    ds.groupBySize(u,v);
                }
            }
            int currcnt=ds.findAns();

            if(currcnt<=k){
                currans=min(currans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return currans;
    }
};