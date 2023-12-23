class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string,int>map;
        int n=path.size();
        int u=0;
        int l=0;
        string str=to_string(u)+"#"+to_string(l);
        map[str]++;

        for(int i=0;i<n;i++){
            if(path[i]=='N')u++;
            else if(path[i]=='S')u--;
            else if(path[i]=='E')l++;
            else{
                l--;
            }
            string str=to_string(u)+"#"+to_string(l);
            if(map.find(str)!=map.end()){
                return true;
            }
            else{
                map[str]++;
            }
        }

        return false;
    }
};