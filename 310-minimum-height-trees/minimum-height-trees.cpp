class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1){
            return {0};
        }
        vector<unordered_set<int>>graph(n);

        for(auto it:edges){
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(graph[i].size()==1){
                q.push(i);
            }
        }

        while(n>2){
            int len=q.size();
            n-=len;

            for(int i=0;i<len;i++){
                int node=q.front();
                q.pop();
                int adjnode=*(graph[node].begin());
                graph[adjnode].erase(node);
                if(graph[adjnode].size()==1){
                    q.push(adjnode);
                }
            }
        }

        vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};