
class disjointSet{
    private:
    vector<int>parent;
    vector<int>size;

    public:
    disjointSet(int n){
        parent.resize(n);
        this->size.resize(n);

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

        if(rootx==rooty)return ;

        if(size[rootx]<=size[rooty]){
            parent[rooty]=rootx;
            size[rooty]+=size[rootx];
        }
        else{
            parent[rootx]=rooty;
            size[rootx]+=size[rooty];
        }
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size(),m=properties[0].size();
        disjointSet ds(n);

        for(int i=0;i<n;i++){
            unordered_map<int,int>map;
            for(int p=0;p<properties[i].size();p++){
                map[properties[i][p]]++;
            }
            for(int j=i+1;j<n;j++){
                unordered_set<int>set;
                for(int p=0;p<properties[j].size();p++){
                    if(map.find(properties[j][p])!=map.end()){
                        set.insert(properties[j][p]);
                    }
                }
                if(set.size()>=k){
                    ds.groupBySize(i,j);
                }
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            if(ds.find(i)==i){
                ans++;
            }
        }
        return ans;
    }
};