class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        
        vector<vector<int>>graph(n);

        vector<vector<vector<int>>>
        dp(1<<(n+1),vector<vector<int>>(n+1,vector<int>(n+1,-1)));

        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int ans=0;

        // oddlength

        for(int i=0;i<n;i++){
            ans=max(ans,1+dfs((1<<i),i,i,graph,label,dp));
        }

        // even legth

        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            if(label[u]==label[v]){
                ans=max(ans,2+dfs((1<<u)|(1<<v),u,v,graph,label,dp));
            }
        }

        return ans;
    }


    int dfs(int bitMask,int l,int r,vector<vector<int>>&graph,string &label,vector<vector<vector<int>>>
        &dp){

            if(dp[bitMask][l][r]!=-1)return dp[bitMask][l][r];

        int ans=0;
        for(auto u:graph[l]){
            if(bitMask&(1<<u)) continue;
            for(auto v:graph[r]){
                if(bitMask&(1<<v)) continue;
                if(u!=v && label[u]==label[v]){
                    ans=max(ans,2+dfs(bitMask|(1<<u)|(1<<v),u,v,graph,label,dp));
                }
            }
        }
        return dp[bitMask][l][r]=ans;
    }
};