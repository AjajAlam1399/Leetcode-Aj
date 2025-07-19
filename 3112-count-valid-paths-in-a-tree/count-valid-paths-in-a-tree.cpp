class dsu{
    public:
    vector<int>size;
    vector<int>parent;

    dsu(int n){
        size.resize(n,1);
        parent.resize(n);

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
    long long findSize(int x){
        int rootx=find(x);
        return size[rootx];
    }
};

class Solution {
    using ll = long long;
    const int N = 1e5 + 2;
    vector<int> isPrime;

public:
    Solution() {
        isPrime.resize(N, 1);
        isPrime[1] = false;
        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n+1);

        dsu ds(n+1);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);

            if(isPrime[u] || isPrime[v]){
                continue;
            }
            ds.groupBySize(u,v);
        }

        ll ans=0;

        for(int i=2;i<=n;i++){
            if(isPrime[i]){
                ll total=1;
                for(auto adjNode : graph[i]){
                    if(!isPrime[adjNode]){
                        total+=ds.findSize(adjNode);
                    }
                }
                // cout<<i<<" "<<total<<endl;
                for(auto adjNode : graph[i]){
                    if(!isPrime[adjNode]){
                        ll size=ds.findSize(adjNode);
                        total-=size;
                        ans+=1LL*total*size;
                    }
                }
            }
        }

        return ans;
    }
};