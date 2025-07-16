class Solution {
    using ll=long long;
    using  pp=pair<ll,ll>;
    int N;
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();

        N=n;

        vector<pp>graph[N];

        for(int i=1;i<n;i++){
            graph[i].push_back({parent[i],s[i]-'a'});
            graph[parent[i]].push_back({i,s[i]-'a'});
        }
        ll ans=0;
        unordered_map<ll,ll>map;
        map[0]=1;
        dfs(0,-1,0,graph,s,map,ans);
        return ans;
    }

    void dfs(int node,int parent,int bitMask,vector<pp>graph[],string &s,unordered_map<ll,ll>&map,ll &ans){

        for(auto [adjnode,val] :graph[node]){
            if(adjnode==parent)continue;
            ll temp=bitMask;
            temp^=1<<val;
            ans+=map[temp];
            for(int i=0;i<26;i++){
                ans+=map[temp^(1<<i)];
            }
            map[temp]++;
            dfs(adjnode,node,bitMask^(1<<val),graph,s,map,ans);
        }
    }
};