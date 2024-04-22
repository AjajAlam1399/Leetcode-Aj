class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        unordered_set<string>set;
        vector<vector<int>>graph(10);

        for(int i=0;i<=9;i++){
            if(i==0){
                graph[0].push_back(1);
                graph[0].push_back(9);
            }
            else if(i==9){
                graph[9].push_back(0);
                graph[9].push_back(8);
            }
            else{
                graph[i].push_back(i+1);
                graph[i].push_back(i-1);
            }
        }
       
        for(int i=0;i<n;i++){
            set.insert(deadends[i]);
        }
        if(set.find("0000")!=set.end())return -1;
        queue<string>q;
        // unordered_set<string>processed;
        q.push({"0000"});
        set.insert("0000");
        int level=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string node=q.front();
                q.pop();
                if(node==target){
                    return level;
                }
                // if(processed.find(node)!=processed.end()){
                //     continue;
                // }
                // processed.insert(node);
                for(int i=0;i<4;i++){
                    string newstr=node;
                    for(auto adj:graph[node[i]-'0']){
                        newstr[i]=adj+'0';
                        if(set.find(newstr)==set.end()){
                            set.insert(newstr);
                            q.push(newstr);
                        }
                    }
                    
                }
            }
            level++;
        }
        return -1;
    }
};