class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>>reachable(n,vector<int>(n,1e9));
        for(auto it :prerequisites){
            reachable[it[0]][it[1]]=1;
        }


        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(reachable[i][k]!=1e9 && reachable[k][j]!=1e9){
                        reachable[i][j]=min(reachable[i][j],reachable[i][k]+reachable[k][j]);
                    }
                }
            }
        }
        vector<bool>ans(queries.size(),false);

        for(int i=0;i<queries.size();i++){
            ans[i]=reachable[queries[i][0]][queries[i][1]]!=1e9?true:false;
        }
        return ans;
    }

    void fun(int i,int j,vector<vector<bool>>&reachable,vector<vector<int>>&graph){
        if(i!=j)reachable[i][j]=true;

        for(auto adjnode:graph[j]){
            fun(i,adjnode,reachable,graph);
        }
    }
   
};