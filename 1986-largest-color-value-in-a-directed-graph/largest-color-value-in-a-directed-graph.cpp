class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();

        vector<int>indegree(n+1);
        vector<vector<int>>graph(n);

        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>>vec(n,vector<int>(26,0));

        queue<int>q;
        int cnt=0,ans=1;
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
                vec[i][colors[i]-'a']++;
                // ans=max(vec[i][color[i]-'a']);
                cnt++;
            }

        }

        while(!q.empty()){
            auto node=q.front();
            int ind=colors[node]-'a';
            q.pop();

            for(auto adjnode: graph[node]){
                for(int i=0;i<26;i++){
                    vec[adjnode][i]=max(vec[adjnode][i],vec[node][i]);
                }
                indegree[adjnode]--;
                if(!indegree[adjnode]){
                    vec[adjnode][colors[adjnode]-'a']++;
                    q.push(adjnode);
                    cnt++;
                }
            }

        }

        if(cnt<n)return -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                ans=max(ans,vec[i][j]);
            }
        }

        return ans;
    }
};