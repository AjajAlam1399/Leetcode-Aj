class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>graph[n];

        for(int i=0;i<n;i++){
            if(i+1!=n){
                graph[i].push_back(i+1);
            }
        }
        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int currans=fun(graph,queries[i][0],queries[i][1],n);
            ans.push_back(currans);
        }
        return ans;
    }

    int fun(vector<int>graph[],int newi,int newj,int n){
        graph[newi].push_back(newj);
        vector<int>visted(n,false);
        queue<int>q;
        q.push(0);
        visted[0]=true;

        int level=0;
        while(!q.empty()){

            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();

                if(node==n-1)return level;

                for(auto adjnode:graph[node]){
                    if(!visted[adjnode]){
                        q.push(adjnode);
                        visted[adjnode]=true;
                    }
                }
            }
            level++;
        }
        return level;
    }
};