class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>graph;
        unordered_map<int,int>degree;

        for(auto it : pairs){
            if(graph.find(it[0])==graph.end()){
                graph[it[0]]={it[1]};
            }
            else{
                graph[it[0]].push_back(it[1]);
            }
            degree[it[0]]++;
            degree[it[1]]--;
        }
        int startNode=-1;
        for(auto it : degree){
            if(startNode==-1)startNode=it.first;
            if(it.second>0){
                startNode=it.first;
                break;
            }
        }
        vector<int>vec;
        fun(startNode,graph,vec);
        vector<vector<int>>ans;
        
        for(int i=vec.size()-1;i>=1;i--){
            ans.push_back({vec[i],vec[i-1]});
        }

        return ans;
    }

    void fun(int node,unordered_map<int,vector<int>>&graph,
    vector<int>&vec){
        while(!graph[node].empty()){
            auto adjnode=graph[node].back();
            graph[node].pop_back();
            fun(adjnode,graph,vec);
        }
        vec.push_back(node);
    }
};