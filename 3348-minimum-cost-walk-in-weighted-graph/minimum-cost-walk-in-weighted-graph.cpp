
class disjoint{
    private:
    vector<int>parent;
    vector<int>size;
    vector<vector<int>>bit;
    void mergeBit(int x,int w){
        for(int i=31;i>=0;i--){
            int b=w&(1<<i);
            if(!b){
                bit[x][i]=0;
            }
            else{
                if(bit[x][i]==-1){
                    bit[x][i]=1;
                }
            }
        }
    }
    void mergebit(int x,vector<int>setBit){
        for(int i=31;i>=0;i--){
            if(setBit[i]==0){
                bit[x][i]=0;
            }
            else if(setBit[i]==1  && bit[x][i]==-1){
                bit[x][i]=1;
            }
        }
    }
    public:
    disjoint(int size){
        parent.resize(size);
        this->size.resize(size);
        bit.resize(size);
        for(int i=0;i<size;i++){
            parent[i]=i;
            bit[i]=vector<int>(32,-1);
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void groupBySize(int x,int y,int w){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx==rooty){
            mergeBit(rootx,w);
            return;
        }
        if(size[rootx]<=size[rooty]){
            parent[rootx]=rooty;
            size[rooty]+=size[rootx];
            mergebit(rooty,bit[rootx]);
            mergeBit(rooty,w);
        }
        else{
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
            mergebit(rootx,bit[rooty]);
            mergeBit(rootx,w);
        }

    }
    int findAns(int x){
        int ans=0;
        for(int i=0;i<32;i++){
            if(bit[x][i]==1){
                ans|=(1<<i);
            }
        }
        return ans;
    }
    
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        disjoint ds(n);

        for(auto it : edges){
            ds.groupBySize(it[0],it[1],it[2]);
        }
        vector<int>ans(query.size(),-1);
        int i=0;
        for(auto it : query){
            int rootx=ds.find(it[0]);
            int rooty=ds.find(it[1]);
            if(rootx==rooty){
                ans[i]=ds.findAns(rootx);
            }
            i++;
        }
        return ans;

    }
};