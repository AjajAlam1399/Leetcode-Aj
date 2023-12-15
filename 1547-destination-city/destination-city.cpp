class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>set;
        unordered_map<string,int>map;

        for(auto it : paths){
            auto v1=it[0];
            auto v2=it[1];
            map[v1]++;
            if(set.find(v1)==set.end()){
                set.insert(v1);
            }
            if(set.find(v2)==set.end()){
                set.insert(v2);
            }
        }
        string ans="";
        for(auto it:set){
            if(map.find(it)==map.end()){
                ans=it;
                break;
            }
        }
        return ans;
    }
};