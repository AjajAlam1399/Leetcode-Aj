class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>graph;

        for(auto it  :tickets){
            graph[it[0]].insert(it[1]);
        }
        vector<string>ans;
        fun("JFK",graph,ans);
        reverse(ans.begin(),ans.end());
         return ans;
    }
    void fun(string node,unordered_map<string,multiset<string>>&graph,
    vector<string>&ans){

        while(graph[node].size()){
            auto adjnode=*graph[node].begin();
            graph[node].erase(graph[node].begin());
            fun(adjnode,graph,ans);
        }
        ans.push_back(node);
    }
};