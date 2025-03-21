class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>>graph;

        unordered_map<string,int>indgree;

        for(int i=0;i<rec.size();i++){
            for(int j=0;j<ing[i].size();j++){
                graph[ing[i][j]].push_back(rec[i]);
                indgree[rec[i]]++;
            }
        }
        
        unordered_set<string>set;

        queue<string>q;

        for(int i=0;i<sup.size();i++){
            q.push(sup[i]);
        }

        while(!q.empty()){
            string str=q.front();
            q.pop();
            set.insert(str);
            for(auto st:graph[str]){
                indgree[st]--;
                if(indgree[st]==0){
                    q.push(st);
                }
            }
        }

        vector<string>ans;

        for(int i=0;i<rec.size();i++){
            if(set.find(rec[i])!=set.end()){
                ans.push_back(rec[i]);
            }
        }


        return ans;
    }
};