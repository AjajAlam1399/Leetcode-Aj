class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>graph[n];

        for(int i=0;i<invocations.size();i++){
            graph[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int>visted(n,0);
        unordered_set<int>set;
        dfs(k,graph,set,visted);

        vector<int>ans;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!visted[i]){
                if(dfs1(i,graph,set,visted)){
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
            for(int i=0;i<n;i++){
                if(set.find(i)==set.end()){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                    ans.push_back(i);
            }
        }
        return ans;
    }

    void dfs(int node,vector<int>graph[],unordered_set<int>&set,vector<int>&visted){

        set.insert(node);
        visted[node]=1;
        for(auto adjnode:graph[node]){
            if(!visted[adjnode]){
                dfs(adjnode,graph,set,visted);
            }
        }
    }

    bool dfs1(int node,vector<int>graph[],unordered_set<int>&set,vector<int>&visted){
        visted[node]=true;
        for(auto adjnode: graph[node]){
            if(visted[adjnode]){
                if(set.find(adjnode)!=set.end()){
                    return true;
                }
                continue;
            }
            else{
                if(dfs1(adjnode,graph,set,visted)){
                    return true;
                }
            }
        }
        return false;
    }
};