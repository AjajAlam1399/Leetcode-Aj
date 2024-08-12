class Solution {
    int ans;
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        ans=0;
        unordered_map<int,vector<int>>graph;
        int len=INT_MIN;
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        fun(0,-1,graph);
        return ans;
    }
    int fun(int root,int parent,unordered_map<int,vector<int>>&graph){
        
        unordered_set<int>set;
        int res=0;
        bool flag=false;
        for(auto adjnode:graph[root]){
            if(adjnode==parent)continue;
            flag=true;
            int len=fun(adjnode,root,graph);
            set.insert(len);
            res+=len;
        }
        if(!flag){
            // cout<<root<<" ";
            ans++;
            return res+1;
        }
        if(set.size()==1){
            // cout<<root<<" ";
            ans++;
        }
        return res+1;
    }
};