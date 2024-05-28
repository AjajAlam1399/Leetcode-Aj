class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int,int>map;
        unordered_map<int,int>set;

        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];

            if(map.find(ball)!=map.end()){
                if(set[map[ball]]==1){
                    set.erase(map[ball]);
                }
                else{
                    set[map[ball]]--;
                }
                map[ball]=color;
                set[color]++;
            }
            else{
                map[ball]=color;
                set[color]++;
            }

            ans.push_back(set.size());
        }
        return ans;
    }
};