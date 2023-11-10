class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int,vector<int>>map;
        int size=adjacentPairs.size();

        for(auto adj:adjacentPairs){
            map[adj[0]].push_back(adj[1]);
            map[adj[1]].push_back(adj[0]);
        }
        int start;

        for(auto it:map){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }

        vector<int>ans;
        ans.push_back(start);
        unordered_set<int>visted;
        visted.insert(start);

        while(visted.size()!=size+1){
            vector<int>vec=map[ans.back()];
            for(auto v:vec){
                if(visted.find(v)==visted.end()){
                    ans.push_back(v);
                    visted.insert(v);
                    break;
                }
            }
        }
        return ans;
    }
};